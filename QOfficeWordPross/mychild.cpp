#include "mychild.h"

#include <QtWidgets>

MyChild::MyChild()
{
    setAttribute(Qt::WA_DeleteOnClose); //关闭窗口时实现销毁
    isUntitled = true;


}

void MyChild::newFile()  //新建文件
{
    static int sequenceNumber = 1;
    isUntitled = true;
    curFile = tr("Word文档-%1").arg(sequenceNumber++);
    setWindowTitle(curFile);
}

bool MyChild::loadFile(const QString &fileName) //导入文件
{
    if(!fileName.isEmpty())
    {
        if(!QFile::exists(fileName))
            return false;

        QFile file(fileName); //创建一个QFile对象，指定文件路径
        if(!file.open(QFile::ReadOnly))
            return false;

        QByteArray data = file.readAll(); // 读取文件的全部内容

        QTextCodec *codec = Qt::codecForHtml(data);  // 获取适合 HTML 数据的编码
        QString str = codec->toUnicode(data); // 将字节数组解码为 Unicode 字符串

        if(Qt::mightBeRichText(str)) //判断字符串 str 是否可能是富文本（HTML 格式）
        {
            this->setHtml(str);  //将字符串 str 作为 HTML 内容设置到当前对象中
        }
        else
        {
            str = QString::fromLocal8Bit(data); //将字节数组 data 转换为本地编码的字符串
            this->setPlainText(str); //将字符串 str 作为普通文本设置到当前对象中
        }
        setCurrentFile(fileName);
        connect(document(), &QTextDocument::contentsChanged, this, &MyChild::documentWasModified);
        return true;
    }
}

bool MyChild::save() //保存
{
    if(isUntitled)
        return saveAs(); //让用户选择保存路径
    else
    {
        return saveFile(curFile);  //保存到当前文件路径
    }
}

bool MyChild::saveAs() //另存为
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile,
                       tr("HTML 文档(*.htm *.html);;所有文件(*.*)"));
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MyChild::saveFile(QString fileName)
{
    //检查文件名是否以.htm或.html 结尾
    if(!(fileName.endsWith(".htm", Qt::CaseInsensitive) || fileName.endsWith(".html", Qt::CaseInsensitive)))
    {
        fileName += ".html";
    }

    QTextDocumentWriter writer(fileName);
    bool success = writer.write(this->document());
    if(success)
        setCurrentFile(fileName);

    return success;
}

//用户友好型当前文件
QString MyChild::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

//格式字体设置
void MyChild::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    setTextCursor(cursor);
}


// 段落对齐
void MyChild::setAlign(int align)
{
    if(align == 1)
        this->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute); //水平方向靠左对齐
    else if(align == 2)
        this->setAlignment(Qt::AlignCenter); //水平方向居中对齐
    else if(align == 3)
        this->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    else if(align == 4)
        this->setAlignment(Qt::AlignJustify); //水平方向两端对齐
}

//段落编号风格
void MyChild::setStyle(int style)
{
    //多行文本框文本光标插入文本
    QTextCursor cursor = this->textCursor();
    if(style != 0)
    {
        QTextListFormat::Style stylename = QTextListFormat::ListDisc; //样式为圆圈

        switch (style)
        {
            default:
            case 1:
                stylename = QTextListFormat::ListDisc; //样式为圆圈
                break;
            case 2:
                stylename = QTextListFormat::ListCircle; //样式为空心圆圈
                break;
            case 3:
                stylename = QTextListFormat::ListSquare; //样式为方块
                break;
            case 4:
                stylename = QTextListFormat::ListDecimal; //样式为阿拉伯数字
                break;
            case 5:
                stylename = QTextListFormat::ListLowerAlpha; //样式为小写阿拉丁字符，按字母顺序
                break;
            case 6:
                stylename = QTextListFormat::ListUpperAlpha; //样式为大写阿拉丁字符，按字母顺序
                break;
            case 7:
                stylename = QTextListFormat::ListLowerRoman; //样式为小写罗马
                break;
            case 8:
                stylename = QTextListFormat::ListUpperRoman; //样式为小写罗马
                break;
        }

        cursor.beginEditBlock(); //开始一个编辑操作块

        QTextBlockFormat blockFormat = cursor.blockFormat(); //获取当前光标所在文本块的格式
        QTextListFormat listFormat; //用于存储列表格式

        if(cursor.currentList()) //检查当前光标是否位于一个列表项中
        {
            listFormat = cursor.currentList()->format(); //获取该列表的格式
        }
        else
        {
            listFormat.setIndent(blockFormat.indent() + 1); //如果当前光标不在列表项中，设置新列表的缩进级别
            blockFormat.setIndent(0); //将当前缩进设置为 0
            cursor.setBlockFormat(blockFormat); //将修改后的文本块格式应用到当前光标所在的文本块
        }

        listFormat.setStyle(stylename);
        cursor.createList(listFormat); //在当前光标位置创建一个新的列表
        cursor.endEditBlock(); //结束编辑操作块
    }
    else //清除当前光标所在文本块的列表格式
    {
        QTextBlockFormat blockformat;
        blockformat.setObjectIndex(-1);
        cursor.mergeBlockFormat(blockformat);
    }
}

void MyChild::closeEvent(QCloseEvent *event) //处理窗口关闭事件
{
    //在关闭窗口之前，检查是否有未保存的更改
    if(maybeSove())
    {
        event->accept(); //接受关闭事件，关闭窗口
    }
    else
    {
        event->ignore();//忽略关闭事件，不关闭窗口
    }
}

void MyChild::documentWasModified()  //修改文件
{
    //在设置改变时，设置窗口已修改
    setWindowModified(document()->isModified());
}

bool MyChild::maybeSove() //是否保存文件
{
    if(document()->isModified())
        return true;

    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Qt Word"), tr("文件‘%1’已经被修改，是否需要保存？").arg
                               (userFriendlyCurrentFile()), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    if(ret == QMessageBox::Save)
        return save();
    else if(ret == QMessageBox::Cancel)
        return false;

    return true;
}

void MyChild::setCurrentFile(const QString &fileName) //设置当前文件的名称
{
    curFile = QFileInfo(fileName).canonicalFilePath(); //将文件名转换为规范路径，消除冗余部分并解析符号链接。
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

//提取文件名
QString MyChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName(); //从一个完整的文件路径中提取文件的基本名称
}


















