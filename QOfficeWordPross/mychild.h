#ifndef MYCHILD_H
#define MYCHILD_H
#include <QTextEdit>


class MyChild : public QTextEdit
{
    Q_OBJECT
public:
    MyChild();


    void newFile();  //新建文件
    bool loadFile(const QString &fileName); //导入文件
    bool save(); //保存
    bool saveAs(); //另存为
    bool saveFile(QString fileName);
    QString userFriendlyCurrentFile();  //用户建立当前新的文件
    QString currentFile()  //当前文件
    {
        return curFile;
    }

    //格式字体设置
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);

    //对齐
    void setAlign(int align);

    //段落标号风格
    void setStyle(int style);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();  //修改文件


private:
    QString curFile;
    bool isUntitled;  //表示当前文件是否是未命名的

    bool maybeSove(); //是否保存文件
    void setCurrentFile(const QString &fileName); //设置当前文件的名称
    QString strippedName(const QString &fullFileName);  //提取文件名

};

#endif // MYCHILD_H












