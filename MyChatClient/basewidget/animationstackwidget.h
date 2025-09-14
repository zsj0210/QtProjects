#ifndef ANIMATIONSTACKWIDGET_H
#define ANIMATIONSTACKWIDGET_H

#include <QStackedWidget>


class animationStackWidget : public QStackedWidget
{
    Q_OBJECT
    //Qt提供的属性系统，独立于编译器和平台的库
    //Qt属性是基于元数据对象系统 信号和槽
    //需要用用moc进行编译，需要继承QObject
    Q_PROPERTY(float getRotateVal READ getRotateVal WRITE setRotateVal)

public:
    animationStackWidget(QWidget *parent = 0);

    ~animationStackWidget();

    //动画效果
    void animation(int m_nextPageIndex);

    float getRotateVal()  //获取旋转值
    {
        return iRotateVal;
    }
    void setRotateVal(float val) //设置旋转值
    {
        iRotateVal = val;
    }

    float getstartVal()  //获取起始值
    {
        return startVal;
    }
    void setstartVal(float val) //设置起始
    {
        startVal = val;
    }

    float getendVal()  //获取结束值
    {
        return endVal;
    }
    void setendVal(float val) //设置结束值
    {
        endVal = val;
    }

protected:
    void paintEvent(QPaintEvent *event);

private:
    float iRotateVal; //旋转值

    int startVal;
    int endVal;

    int m_nextPageIndex; //下一页

    bool m_isAnimation;

private slots:
    void onValueChanged(const QVariant &value);

    void onFinished();
};

#endif // ANIMATIONSTACKWIDGET_H
