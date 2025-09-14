#include "page01.h"
#include "ui_page01.h"

#include <QPainter>
#include <QTransform>

page01::page01(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page01)
{
    ui->setupUi(this);
}

page01::~page01()
{
    delete ui;
}

void page01::on_pushButton_clicked()
{
    //点击翻转到页面2
    //发送信号出去
    emit page01Clicked();
}

void page01::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    //使用 Qt 的绘图系统在界面上绘制一张图片
    QPixmap pix(":/images/1.png"); //将指定路径的图片加载进来
    p.drawPixmap(QRect(0, 0, 500, 500), pix);//创建了一个矩形区域
}
