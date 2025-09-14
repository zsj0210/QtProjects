#include "myword.h"

//统一图标来源
const QString srcpaths = ":/new/prefix1/images";

MyWord::MyWord(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 500);
    setWindowTitle("Office办公自动化文字编译软件 V2.1");

    mdiArea = new QMdiArea(this);

    //设置水平滚动条的显示策略,Qt::ScrollBarAsNeeded：按需显示
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea); //配置可滚动的 MDI 区域作为主窗口的中央部件

    //更新菜单
    connect(mdiArea, QOverload<QMdiSubWindow*>::of(&QMdiArea::subWindowActivated),
            this, &MyWord::updateMenu);

    //窗口信号
    windowMapper = new QSignalMapper(this);
    //设置active激活窗口
    connect(windowMapper, QOverload<QWidget*>::of(&QSignalMapper::mapped),
            this, &MyWord::setActiveSubWindow);

    createActions();//创建菜单、工具栏、状态栏等相关动作的操作
    createMenus(); //调用创建菜单操作
    updateMenu(); //更新菜单条目
    createToolBars(); //创建工具条
    createStatusBars(); //创建状态栏

}

MyWord::~MyWord()
{
}

void MyWord::closeEvent(QCloseEvent *event) //通过event来控制窗口关闭
{
    // 第一步：尝试关闭所有MDI子窗口
    mdiArea->closeAllSubWindows();
    // 第二步：检查是否还有未关闭的子窗口
    if(mdiArea->currentSubWindow())
    {
        // 若存在未关闭的子窗口，忽略关闭事件（阻止主窗口关闭）
        event->ignore();
    }
    else
    {
        // 若所有子窗口都已关闭，接受关闭事件（允许主窗口关闭）
        event->accept();
    }
}

void MyWord::updateMenu() //更新菜单
{
    //至少有一个子文档打开着的情况
    bool hasMyChild = (activeMyChild() != 0);

    //当有子窗口打开时：
    //启用这些菜单项，允许用户对当前活动文档进行操作
    saveAction->setEnabled(hasMyChild);
    saveAsAction->setEnabled(hasMyChild);
    printAction->setEnabled(hasMyChild);
    printPreviewAction->setEnabled(hasMyChild);

    pasteAction->setEnabled(hasMyChild);

    closeAction->setEnabled(hasMyChild);
    closeAllAction->setEnabled(hasMyChild);
    titleAction->setEnabled(hasMyChild);
    cascadeAction->setEnabled(hasMyChild);
    nextAction->setEnabled(hasMyChild);
    previousAction->setEnabled(hasMyChild);
    separatorAction->setVisible(hasMyChild);


    //文档打开着并且其中有内容被选中的情况
    bool hasSelection = (activeMyChild() && activeMyChild()->textCursor().hasSelection());

    cutAction->setEnabled(hasSelection);
    copyAction->setEnabled(hasSelection);

    textboldAction->setEnabled(hasSelection);
    textitealicAsAction->setEnabled(hasSelection);
    textunderlineAction->setEnabled(hasSelection);
    textleftAction->setEnabled(hasSelection);
    textcenterAction->setEnabled(hasSelection);
    textrithtAction->setEnabled(hasSelection);
    textjustifyAction->setEnabled(hasSelection);
    textcolorAction->setEnabled(hasSelection);

}

void MyWord::updateWindowMenu()//更新窗口菜单
{
    windowMenu->clear();
    windowMenu->addAction(closeAction);
    windowMenu->addAction(closeAllAction);
    windowMenu->addSeparator();

    windowMenu->addAction(titleAction);
    windowMenu->addAction(cascadeAction);
    windowMenu->addSeparator();

    windowMenu->addAction(nextAction);
    windowMenu->addAction(previousAction);
    windowMenu->addAction(separatorAction);

    QList<QMdiSubWindow*>windows = mdiArea->subWindowList();
    separatorAction->setVisible(!windows.isEmpty()); // 当有子窗口时显示分隔线

    //显示当前打开的文档窗口项
    for(int i = 1; i < windows.size(); i++)
    {
        //从 MDI 子窗口中获取实际的文档内容部件，并将其转换为MyChild类型
        MyChild *child = qobject_cast<MyChild*>(windows.at(i)->widget());

        QString text;
        if(i < 9)
        {
            text = tr("&%1 %2").arg(i + 1).arg(child->userFriendlyCurrentFile());
        }
        else
        {
            text = tr("%1 %2").arg(i + 1).arg(child->userFriendlyCurrentFile());
        }

        QAction *action = windowMenu->addAction(text);
        action->setCheckable(true);
        action->setChecked(child == activeMyChild()); //勾选当前活动窗口对应的菜单项

        windowMapper->setMapping(action, windows.at(i));// 建立动作与子窗口的映射关系
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
    }

}

MyChild* MyWord::createMyChild() //创建子窗口操作
{
    MyChild *child = new MyChild;

    mdiArea->addSubWindow(child);
    connect(child, QOverload<bool>::of(&MyChild::copyAvailable), cutAction, &QAction::setEnabled);
    connect(child, QOverload<bool>::of(&MyChild::copyAvailable), copyAction, &QAction::setEnabled);

    return child;
}

void MyWord::createActions() //创建菜单动作
{
    //【文件】菜单栏动作
    //新建
    newAction = new QAction(QIcon(srcpaths + "/filenew.png"), tr("新建(&N)"), this);
    //为菜单项或工具栏按钮（如 "新建" 操作）设置系统标准的快捷键
    newAction->setShortcuts(QKeySequence::New);
    newAction->setToolTip("新建"); //工具栏按钮的提示文本
    newAction->setStatusTip(tr("创建一个新的word文档")); //创建一个状态栏提示文本信息

    connect(newAction, &QAction::triggered, this, &MyWord::newFile);

    //打开
    openAction = new QAction(QIcon(srcpaths + "/fileopen.png"), tr("打开(&O)"), this);
    //为菜单项或工具栏按钮（如 "打开" 操作）设置系统标准的快捷键
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setToolTip("打开"); //工具栏按钮的提示文本
    openAction->setStatusTip(tr("打开已经存在的word文档")); //创建一个状态栏提示文本信息

    connect(openAction, &QAction::triggered, this, &MyWord::openFile);

    //保存
    saveAction = new QAction(QIcon(srcpaths + "/filesave.png"), tr("保存(&S)"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setToolTip("保存");
    saveAction->setStatusTip(tr("保存当前word文档"));

    connect(saveAction, &QAction::triggered, this, &MyWord::saveFile);

    //另存为
    saveAsAction = new QAction(tr("另存为(&A)..."), this);
    saveAsAction->setShortcuts(QKeySequence::SaveAs);
    saveAsAction->setToolTip("另存为");
    saveAsAction->setStatusTip(tr("将word文档另存为..."));

    connect(saveAsAction, &QAction::triggered, this, &MyWord::saveAsFile);

    //打印
    printAction = new QAction(QIcon(srcpaths + "/fileprint.png"), tr("打印(&P)"), this);
    printAction->setShortcuts(QKeySequence::Print);
    printAction->setToolTip("打印");
    printAction->setStatusTip(tr("打印当前word文档"));

    connect(printAction, &QAction::triggered, this, &MyWord::filePrint);

    //打印预览
    printPreviewAction = new QAction(tr("打印预览(&P)"), this);
    printPreviewAction->setToolTip("打印预览");
    printPreviewAction->setStatusTip(tr("打印预览当前word文档"));

    connect(printPreviewAction, &QAction::triggered, this, &MyWord::filePrintPreview);

    //退出操作
    exitAction = new QAction(tr("退出(&X)"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("退出word文档应用程序");
    connect(exitAction, &QAction::triggered, qApp, &QApplication::closeAllWindows);

    //【编辑】菜单栏动作
    //撤销
    undoAction = new QAction(QIcon(srcpaths + "/editundo.png"), tr("撤销(&U)"), this);
    undoAction->setShortcuts(QKeySequence::Undo);
    undoAction->setToolTip("撤销");
    undoAction->setStatusTip(tr("撤销当前操作"));

    connect(undoAction, &QAction::triggered, this, &MyWord::undo);

    //重做
    redoAction = new QAction(QIcon(srcpaths + "/editredo.png"), tr("重做(&R)"), this);
    redoAction->setShortcuts(QKeySequence::Redo);
    redoAction->setToolTip("重做");
    redoAction->setStatusTip(tr("恢复之前的操作"));

    connect(redoAction, &QAction::triggered, this, &MyWord::redo);

    //剪切
    cutAction = new QAction(QIcon(srcpaths + "/editcut.png"), tr("剪切(&T)"), this);
    cutAction->setShortcuts(QKeySequence::Redo);
    cutAction->setToolTip("剪切");
    cutAction->setStatusTip(tr("剪切所选内容"));

    connect(cutAction, &QAction::triggered, this, &MyWord::cut);

    //复制
    copyAction = new QAction(QIcon(srcpaths + "/editcopy.png"), tr("复制(&C)"), this);
    copyAction->setShortcuts(QKeySequence::Copy);
    copyAction->setToolTip("复制");
    copyAction->setStatusTip(tr("复制所选内容"));

    connect(copyAction, &QAction::triggered, this, &MyWord::copy);

    //粘贴
    pasteAction = new QAction(QIcon(srcpaths + "/editpaste.png"), tr("粘贴(&P)"), this);
    pasteAction->setShortcuts(QKeySequence::Paste);
    pasteAction->setToolTip("粘贴");
    pasteAction->setStatusTip(tr("粘贴所复制的内容"));

    connect(pasteAction, &QAction::triggered, this, &MyWord::paste);

    //【格式】字体-菜单栏动作
    //加粗
    textboldAction = new QAction(QIcon(srcpaths + "/textbold.png"), tr("加粗(&B)"), this);
    textboldAction->setChecked(true); //设置选中状态
    textboldAction->setToolTip("加粗");
    textboldAction->setStatusTip(tr("将选择的文字进行加粗操作"));
    //设置粗体字体样
    connect(textboldAction, &QAction::triggered, this, &MyWord::textBold);

    //倾斜
    textitealicAsAction = new QAction(QIcon(srcpaths + "/textitalic.png"), tr("倾斜(&I)"), this);
    textitealicAsAction->setChecked(true); //设置选中状态
    textitealicAsAction->setShortcuts(QKeySequence::Italic);
    textitealicAsAction->setToolTip("倾斜");
    textitealicAsAction->setStatusTip(tr("将选择的文字进行倾斜操作"));

    connect(textitealicAsAction, &QAction::triggered, this, &MyWord::textItalic);

    //下划线
    textunderlineAction = new QAction(QIcon(srcpaths + "/textunder.png"), tr("下划线(&U)"), this);
    textunderlineAction->setChecked(true); //设置选中状态
    textunderlineAction->setShortcuts(QKeySequence::Underline);
    textunderlineAction->setToolTip("下划线");
    textunderlineAction->setStatusTip(tr("将选择的文字进行添加下划线操作"));
    //设置倾斜字体样式

    connect(textunderlineAction, &QAction::triggered, this, &MyWord::textUnderline);

    //（段落）菜单栏动作
    QActionGroup *group = new QActionGroup(this); //提供了一种简洁的方式来管理互斥的功能选项
    connect(group, QOverload<QAction*>::of(&QActionGroup::triggered), this, &MyWord::textAlign);

    if(QApplication::isLeftToRight()) //检测应用程序当前布局方向的静态方法
    {
        textleftAction = new QAction(QIcon(srcpaths + "/textleft.png"), tr("左对齐(&L)"), group);
        textcenterAction = new QAction(QIcon(srcpaths + "/textcenter.png"), tr("居中对齐(&C)"), group);
        textrithtAction = new QAction(QIcon(srcpaths + "/textright.png"), tr("右对齐(&R)"), group);
    }
    else
    {
        textrithtAction = new QAction(QIcon(srcpaths + "/textright.png"), tr("右对齐(&R)"), group);
        textcenterAction = new QAction(QIcon(srcpaths + "/textcenter.png"), tr("居中对齐(&C)"), group);
        textleftAction = new QAction(QIcon(srcpaths + "/textleft.png"), tr("左对齐(&L)"), group);
    }
    textjustifyAction = new QAction(QIcon(srcpaths + "/textjustify.png"), tr("两端对齐(&J)"), group);

    textleftAction->setCheckable(true);
    textleftAction->setToolTip("左对齐");
    textleftAction->setStatusTip(tr("将选中的内容进行左对齐"));

    textcenterAction->setCheckable(true);
    textcenterAction->setToolTip("居中对齐");
    textcenterAction->setStatusTip(tr("将选中的内容进行居中对齐"));

    textrithtAction->setCheckable(true);
    textrithtAction->setToolTip("右对齐");
    textrithtAction->setStatusTip(tr("将选中的内容进行右对齐"));

    textjustifyAction->setCheckable(true);
    textjustifyAction->setToolTip("两端对齐");
    textjustifyAction->setStatusTip(tr("将选中的内容进行两端对齐"));

    QPixmap pix(16, 16);
    pix.fill(Qt::red);
    textcolorAction = new QAction(pix, tr("颜色(&C)..."), this);
    textcolorAction->setToolTip("颜色");
    textcolorAction->setStatusTip("设置文本内容的颜色");
    connect(textcolorAction, &QAction::triggered, this, &MyWord::textColor);


    //【窗口】菜单栏动作
    //关闭窗口
    closeAction = new QAction(tr("关闭(&O)"), this);
    closeAction->setStatusTip(tr("关闭活动word文档子窗口"));
    connect(closeAction, &QAction::triggered, mdiArea, &QMdiArea::closeActiveSubWindow);

    //关闭所有窗口
    closeAllAction = new QAction(tr("关闭所有窗口(&A)"), this);
    closeAllAction->setStatusTip("关闭所有活动word文档子窗口");
    connect(closeAllAction, &QAction::triggered, mdiArea, &QMdiArea::closeAllSubWindows);

    //平铺
    titleAction = new QAction(tr("平铺(&T)"), this);
    titleAction->setStatusTip("平铺子窗口");
    connect(titleAction, &QAction::triggered, mdiArea, &QMdiArea::tileSubWindows);

    //层叠
    cascadeAction = new QAction(tr("层叠(&T)"), this);
    cascadeAction->setStatusTip("层叠子窗口");
    connect(cascadeAction, &QAction::triggered, mdiArea, &QMdiArea::cascadeSubWindows);

    //下一个窗口
    nextAction = new QAction(tr("下一个(&N)"), this);
    nextAction->setStatusTip("下一个窗口");
    connect(nextAction, &QAction::triggered, mdiArea, &QMdiArea::activateNextSubWindow);

    //上一个窗口
    previousAction = new QAction(tr("上一个(&P)"), this);
    previousAction->setStatusTip("上一个窗口");
    connect(previousAction, &QAction::triggered, mdiArea, &QMdiArea::activatePreviousSubWindow);

    //在菜单或工具栏中创建一个分隔线
    separatorAction = new QAction(this);
    separatorAction->setSeparator(true);

    //【帮助】菜单栏动作
    //帮助
    aboutAction = new QAction(tr("关于(&A)"), this);
    aboutAction->setStatusTip("帮助");
    connect(aboutAction, &QAction::triggered, this, &MyWord::about);

    //关于qt
    aboutQtAction = new QAction(tr("关于Qt(&QT)"), this);
    aboutQtAction->setStatusTip("关于Qt库相关信息");
    connect(aboutQtAction, &QAction::triggered, this, &QApplication::aboutQt);
}

void MyWord::createMenus() //创建菜单
{
    //文件菜单
    fileMenu = menuBar()->addMenu(tr("文件(&F)"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator(); //添加分隔符
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator(); //添加分隔符
    fileMenu->addAction(printAction);
    fileMenu->addAction(printPreviewAction);
    fileMenu->addSeparator(); //添加分隔符
    fileMenu->addAction(exitAction);

    //编辑菜单
    editMenu = menuBar()->addMenu(tr("编辑(&E)"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator(); //添加分隔符
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    //格式菜单
    formatMenu = menuBar()->addMenu(tr("格式(&O)"));
    fontMenu = formatMenu->addMenu(tr("字体(&D)"));
    fontMenu->addAction(textboldAction);
    fontMenu->addAction(textitealicAsAction);
    fontMenu->addAction(textunderlineAction);

    alignMenu = formatMenu->addMenu(tr("段落(&A)"));
    alignMenu->addAction(textleftAction);
    alignMenu->addAction(textcenterAction);
    alignMenu->addAction(textrithtAction);
    alignMenu->addAction(textjustifyAction);
    formatMenu->addAction(textcolorAction); //颜色

    //窗口菜单
    windowMenu = menuBar()->addMenu(tr("窗口(&W)"));
    updateWindowMenu(); //更新窗口
    connect(windowMenu, &QMenu::aboutToShow, this, &MyWord::updateWindowMenu);
    windowMenu->addSeparator(); //添加分隔符
    windowMenu->addAction(closeAction);
    windowMenu->addAction(closeAllAction);
    windowMenu->addSeparator(); //添加分隔符
    windowMenu->addAction(titleAction);
    windowMenu->addAction(cascadeAction);
    windowMenu->addSeparator(); //添加分隔符
    windowMenu->addAction(nextAction);
    windowMenu->addAction(previousAction);

    //帮助菜单
    helpMenu = menuBar()->addMenu(tr("帮助(&H)"));
    helpMenu->addAction(aboutAction);
    helpMenu->addSeparator(); //添加分隔符
    helpMenu->addAction(aboutQtAction);

}

void MyWord::createToolBars() //创建工具条
{
    //文件
    fileToolBar = addToolBar(tr("文件"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(saveAsAction);
    fileToolBar->addSeparator(); //添加分隔符
    fileToolBar->addAction(printAction);

    //编辑
    editToolBar = addToolBar(tr("编辑"));
    editToolBar->addAction(undoAction);
    editToolBar->addAction(redoAction);
    editToolBar->addSeparator(); //添加分隔符
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);

    //格式
    formatToolBar = addToolBar(tr("格式"));
    formatToolBar->addAction(textboldAction);
    formatToolBar->addAction(textitealicAsAction);
    formatToolBar->addAction(textunderlineAction);
    formatToolBar->addSeparator(); //添加分隔符
    formatToolBar->addAction(textleftAction);
    formatToolBar->addAction(textcenterAction);
    formatToolBar->addAction(textrithtAction);
    formatToolBar->addAction(textjustifyAction);
    formatToolBar->addSeparator(); //添加分隔符
    formatToolBar->addAction(textcolorAction);

    //组合工具栏
    //组合选择
    addToolBarBreak(Qt::TopToolBarArea); //指定在顶部工具栏区域添加分隔
    comboToolBar = addToolBar(tr("组合选择"));
    comboStyle = new QComboBox(this);
    comboToolBar->addWidget(comboStyle);
    comboStyle->addItem("标准");
    comboStyle->addItem("项目符号 (●)");
    comboStyle->addItem("项目符号 (○)");
    comboStyle->addItem("项目符号 (■)");
    comboStyle->addItem("编号 (⒈⒉⒊)");
    comboStyle->addItem("编号 ( a.b.c.)");
    comboStyle->addItem("编号 ( A.B.C.)");
    comboStyle->addItem("编号 (ⅰ.ⅱ.ⅲ.)");
    comboStyle->addItem("编号 (Ⅰ.Ⅱ.Ⅲ.)");
    comboStyle->setStatusTip("段落添加标号或编号");
    connect(comboStyle, QOverload<int>::of(&QComboBox::activated), this, &MyWord::textStyle);

    //改变字体样式
    comboFont = new QFontComboBox(this);
    comboToolBar->addWidget(comboFont);
    comboFont->setStatusTip("更改字体");
    connect(comboFont, QOverload<const QString&>::of(&QFontComboBox::activated), this, &MyWord::textFamily);

    //改变字体大小
    comboSize = new QComboBox(this);
    comboToolBar->addWidget(comboSize);
    comboSize->setEditable(true); //设置为可编辑状态
    comboSize->setStatusTip("更改字体大小");

    QFontDatabase db; // 创建字体数据库对象，用于查询系统字体信息s
    QList<int> sizes = db.standardSizes();
    for(int size : sizes)
    {
        comboSize->addItem(QString::number(size));// 将每个大小转换为字符串并添加到下拉框
    }

}

void MyWord::createStatusBars() //创建状态栏
{
    statusBar()->showMessage(tr("准备就绪状态"));
}

MyChild* MyWord::activeMyChild() //激活子窗口
{
    if(QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow())
    {
        return qobject_cast<MyChild*>(activeSubWindow->widget());
    }
    return nullptr;
}

QMdiSubWindow* MyWord::findMyChild(const QString &fileName) //查找子窗口
{
    QString cannoicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach(QMdiSubWindow *window, mdiArea->subWindowList())
    {
        MyChild *myChild = qobject_cast<MyChild*>(window->widget());
        if(myChild->currentFile() == cannoicalFilePath)
            return window;
    }
    return 0;
}

void MyWord::setActiveSubWindow(QWidget *window) //设置active激活窗口
{
    if (!window)
        return;
    mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));

}

void MyWord::newFile() //新建
{
    MyChild *child = createMyChild();
    child->newFile();
    child->show();
    enabledText(); //使得字体设置菜单可用
}

void MyWord::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开"), QString(),
                       tr("HTML 文档(*.htm *.html);;所有文件(*.*)"));

    if(!fileName.isEmpty())
    {
        QMdiSubWindow *existing = findMyChild(fileName);

        if(existing)
        {
            mdiArea->setActiveSubWindow(existing);
        }

        MyChild *child = createMyChild();
        if(child->loadFile(fileName))
        {
            statusBar()->showMessage(tr("文件已经加载"), 2000);
            child->show();
            enabledText();
        }
        else
        {
            child->close();
        }
    }
}

void MyWord::saveFile()
{
    if(activeMyChild() && activeMyChild()->save())
    {
        statusBar()->showMessage(tr("Word文档保存成功"), 2000); //状态栏显示 "word 文档保存成功"，并在 2 秒后自动消失
    }
}
void MyWord::saveAsFile()
{
    if(activeMyChild() && activeMyChild()->saveAs())
    {
        statusBar()->showMessage(tr("Word文档另存为成功"), 2000); //状态栏显示 "word 文档保存成功"，并在 2 秒后自动消失
    }
}

void MyWord::filePrint() //打印
{
    QPrinter printer(QPrinter::HighResolution); //初始化一个高分辨率打印机
    QPrintDialog *pdlg = new QPrintDialog(&printer, this);
    //如果有选中文本，启用"打印选择区域"选项
    if(activeMyChild()->textCursor().hasSelection())
        pdlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    pdlg->setWhatsThis(tr("打印文档")); //设置对话框的帮助文本
    if(pdlg->exec() == QDialog::Accepted) //用户确认打印设置后
        activeMyChild()->print(&printer); //将当前文档内容发送到打印机

    delete pdlg;

}

void MyWord::filePrintPreview() //文件打印预览
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, SIGNAL(paintRequested(QPinter*)), SLOT(printPreview(QPrinter*)));
}

void MyWord::printPreview(QPrinter* printer)  //打印预览
{
    activeMyChild()->print(printer);
}

void MyWord::undo() //撤销
{
    if(activeMyChild())
        activeMyChild()->undo();
}

void MyWord::redo() //重做
{
    if(activeMyChild())
        activeMyChild()->redo();
}

void MyWord::cut()//剪切
{
    if(activeMyChild())
        activeMyChild()->cut();
}

void MyWord::copy() //复制
{
    if(activeMyChild())
        activeMyChild()->copy();
}

void MyWord::paste() //粘贴
{
    if(activeMyChild())
        activeMyChild()->paste();
}

void MyWord::enabledText() //创建文本相关格式
{
    textboldAction->setEnabled(true);
    textitealicAsAction->setEnabled(true);
    textunderlineAction->setEnabled(true);
    textleftAction->setEnabled(true);
    textcenterAction->setEnabled(true);
    textrithtAction->setEnabled(true);
    textjustifyAction->setEnabled(true);
    textcolorAction->setEnabled(true);
}

void MyWord::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(textboldAction->isChecked() ? QFont::Bold : QFont::Normal);
    if(activeMyChild())
        activeMyChild()->mergeFormatOnWordOrSelection(fmt); // 修正为正确方法名
}

void MyWord::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(textitealicAsAction->isChecked());
    if(activeMyChild())
        activeMyChild()->mergeFormatOnWordOrSelection(fmt);
}

void MyWord::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(textunderlineAction->isChecked());
    if(activeMyChild())
        activeMyChild()->mergeFormatOnWordOrSelection(fmt);
}

void MyWord::textAlign(QAction *a)
{
    if(activeMyChild())
    {
        if(a == textleftAction)
            activeMyChild()->setAlign(1);
        else if(a == textcenterAction)
            activeMyChild()->setAlign(2);
        else if(a == textrithtAction)
            activeMyChild()->setAlign(3);
        else if(a == textjustifyAction)
            activeMyChild()->setAlign(4);
    }

}

void MyWord::textStyle(int styleIndex)
{
    if(activeMyChild())
        activeMyChild()->setStyle(styleIndex);

}

void MyWord::textFamily(const QString &f)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(f);
    if(activeMyChild())
        activeMyChild()->mergeFormatOnWordOrSelection(fmt);

}

void MyWord::textSize(const QString &s)
{
    qreal pointsize = s.toFloat(); //将字符串参数s转换为浮点数作为字体大小
    if(s.toFloat() > 0)
    {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointsize);
        if(activeMyChild())
            activeMyChild()->mergeFormatOnWordOrSelection(fmt);
    }

}

void MyWord::textColor()
{
    if(activeMyChild())
    {
        // 打开颜色选择对话框，默认选中当前文本颜色
        QColor color = QColorDialog::getColor(activeMyChild()->textColor(), this);

        if(!color.isValid())
            return ;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activeMyChild()->mergeFormatOnWordOrSelection(fmt);
        colorChanged(color);
    }

}

void MyWord::fontChanged(const QFont &f)
{
    // 更新字体下拉框的选中项
    comboFont->setCurrentIndex(comboFont->findText(QFontInfo(f).family()));
    // 更新字体大小下拉框的选中项
    comboSize->setCurrentIndex(comboSize->findText(QString::number(f.pointSize())));

    // 更新粗体、斜体、下划线按钮的选中状态
    textboldAction->setChecked(f.bold());
    textitealicAsAction->setChecked(f.italic());
    textunderlineAction->setChecked(f.underline());

}

void MyWord::colorChanged(const QColor &c)
{
    QPixmap pix(16, 16);
    pix.fill(c);//用指定颜色填充该 Pixmap
    textcolorAction->setIcon(pix);

}

void MyWord::alignmentChanged(Qt::Alignment a)
{
    if(a & Qt::AlignLeft)
        textleftAction->setChecked(true);
    else if(a & Qt::AlignCenter)
        textcenterAction->setChecked(true);
    else if(a & Qt::AlignRight)
        textrithtAction->setChecked(true);
    else if(a & Qt::AlignJustify)
        textjustifyAction->setChecked(true);

}

void MyWord::about()
{
    QMessageBox::about(this, tr("关于"), tr("此软件是基于Qt5实现的文字处理软件！！！"));
}











