#include "animationstackwidget.h"
#include <QPropertyAnimation> //实现属性动画
#include <QPainter>
#include <QTransform>

animationStackWidget::animationStackWidget(QWidget *parent)
    : QStackedWidget(parent)
{
    m_nextPageIndex = 0;
    m_isAnimation = false;
}

animationStackWidget::~animationStackWidget()
{

}

void animationStackWidget::animation(int pageIndex)
{
    if(m_isAnimation)
    {
        return;
    }

    int offsetX = frameRect().width();
    int offsetY = frameRect().height();
    widget(pageIndex)->setGeometry(0, 0, offsetX, offsetY);

    m_nextPageIndex = pageIndex;
    //propertyName
    QPropertyAnimation *animation = new QPropertyAnimation(this, "getRotateVal");

    animation->setDuration(700);
    //设定线性的缓动曲线
    animation->setEasingCurve(QEasingCurve::Linear);
    //设置动画起始值
    animation->setStartValue(startVal);
    //设置动画结束值
    animation->setEndValue(endVal);

    QObject::connect(animation, &QPropertyAnimation::valueChanged, this, &animationStackWidget::onValueChanged);
    QObject::connect(animation, &QPropertyAnimation::finished, this, &animationStackWidget::onFinished);

    m_isAnimation = true;
    animation->start();
    currentWidget()->hide(); //隐藏当前活动控件的代码

}

void animationStackWidget::onValueChanged(const QVariant &value)
{
    //值改变后
    update();
}

void animationStackWidget::onFinished()
{
    m_isAnimation = false;
    //动画结束
    widget(m_nextPageIndex)->show(); //通过索引获取子控件
    widget(m_nextPageIndex)->raise(); //将控件提升到父容器的堆叠顺序顶部

    setCurrentWidget(widget(m_nextPageIndex));

    update();
}

void animationStackWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    if(m_isAnimation)
    {
        //判断旋转值
        if(iRotateVal > 0 && iRotateVal <= 90)
        {
            QPixmap pix(currentWidget()->size()); //创建与控件大小相同的 QPixmap 对象,存储图像数据
            currentWidget()->render(&pix);
            //旋转
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(iRotateVal, Qt::YAxis);
            p.setTransform(transform);
            p.drawPixmap(-1 * width() / 2, 0, pix); //创建了一个矩形区域
        }
        else if(iRotateVal > 90 && iRotateVal <= 180)
        {
            QPixmap pix( widget(m_nextPageIndex)->size());
            widget(m_nextPageIndex)->render(&pix);
            //旋转
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(iRotateVal + 180, Qt::YAxis);
            p.setTransform(transform);
            p.drawPixmap(-1 * width() / 2, 0, pix); //创建了一个矩形区域
        }
        else if(iRotateVal > -180 && iRotateVal <= -90)
        {
            QPixmap pix( widget(m_nextPageIndex)->size());
            widget(m_nextPageIndex)->render(&pix);

            //旋转
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(iRotateVal + 180, Qt::YAxis);
            p.setTransform(transform);
            p.drawPixmap(-1 * width() / 2, 0, pix); //创建了一个矩形区域
        }
        else if(iRotateVal > -90 && iRotateVal <= 0)
        {
            QPixmap pix(currentWidget()->size());
            currentWidget()->render(&pix);
            //旋转
            QTransform transform;
            transform.translate(width() / 2, 0);
            transform.rotate(iRotateVal, Qt::YAxis);
            p.setTransform(transform);
            p.drawPixmap(-1 * width() / 2, 0, pix); //创建了一个矩形区域
        }
    }
    else
    {
        QWidget::paintEvent(event);
    }

}


