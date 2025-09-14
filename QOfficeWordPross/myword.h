#ifndef MYWORD_H
#define MYWORD_H

#include <QMainWindow>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <mychild.h>
#include <QtWidgets>



class MyChild;

class QAction; //此类被创建后必须将它添加到菜单和工具栏中，然后将它链接到实现action功能的槽函数
class QMenu; //菜单栏,挂载到菜单栏QMenuBar上面的
class QComboBox; //向用户展示的选项列表（组合款）
class QFontComboBox; //字体下拉列表框，选择字体，不能被编辑
class QMdiArea; //提供一个可以同时显示多个文档窗口的区域
class QMdiSubWindow; //是QMdiArea的子窗口，用于在 MDI 界面中显示和管理多个文档或视图
class QSignalMapper; //收集一些列的无参信号


class MyWord : public QMainWindow
{
    Q_OBJECT

public:
    MyWord(QWidget *parent = nullptr);
    ~MyWord();


protected:
    void closeEvent(QCloseEvent *event); //通过event来控制窗口关闭


private:
    //文件下拉框中
    void newFile(); //新建
    void openFile();
    void saveFile();
    void saveAsFile();
    void filePrint(); //打印
    void filePrintPreview(); //文件打印预览
    void printPreview(QPrinter* printer);  //打印预览

    //编辑下拉框中
    void undo(); //撤销
    void redo(); //重做
    void cut(); //剪切
    void copy(); //复制
    void paste(); //粘贴
    void about(); //关于

    //格式下拉框中
    void textBold();
    void textItalic();
    void textUnderline();
    void textAlign(QAction *a);
    void textStyle(int styleIndex);
    void textFamily(const QString &f);
    void textSize(const QString &s);
    void textColor();

    void updateMenu(); //更新菜单
    void updateWindowMenu(); //更新窗口菜单
    void setActiveSubWindow(QWidget *window); //设置active激活窗口
    MyChild* createMyChild(); //创建子窗口

private:
    void createActions(); //创建菜单操作
    void createMenus(); //创建菜单
    void createToolBars(); //创建工具条
    void createStatusBars(); //创建状态栏
    void enabledText(); //创建文本相关格式
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);
    MyChild* activeMyChild(); //激活子窗口
    QMdiSubWindow* findMyChild(const QString &fileName); //查找子窗口

    QMdiArea* mdiArea; //多文档窗口管理器
    QSignalMapper* windowMapper; //窗口信号

    //定义菜单
    QMenu* fileMenu; //定义文件菜单
    QMenu* editMenu;  //编辑菜单
    QMenu* formatMenu; //格式菜单
    QMenu* fontMenu; //字体
    QMenu* alignMenu; //对齐
    QMenu* windowMenu; //窗口菜单
    QMenu* helpMenu;  //帮助菜单

    //工具栏
    QToolBar* fileToolBar;
    QToolBar* editToolBar;
    QToolBar* formatToolBar;
    QToolBar* comboToolBar;
    QComboBox* comboStyle; //子控件，标准组合框
    QComboBox* comboSize; //子控件，字体大小组合框
    QFontComboBox* comboFont; //子控件，字体组合框


    //菜单动作实现Action
    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* printAction;
    QAction* printPreviewAction;
    QAction* exitAction;

    QAction* undoAction;
    QAction* redoAction;
    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;

    QAction* textboldAction;
    QAction* textitealicAsAction;
    QAction* textunderlineAction;
    QAction* textleftAction;
    QAction* textcenterAction;
    QAction* textrithtAction;
    QAction* textjustifyAction;
    QAction* textcolorAction;

    QAction* closeAction;
    QAction* closeAllAction;
    QAction* titleAction;
    QAction* cascadeAction;
    QAction* nextAction;
    QAction* previousAction;
    QAction* separatorAction;

    QAction* aboutAction;
    QAction* aboutQtAction;


};
#endif // MYWORD_H















