#include "page02.h"
#include "ui_page02.h"

#include <QPainter>
#include <QTransform>

page02::page02(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page02)
{
    ui->setupUi(this);
}

page02::~page02()
{
    delete ui;
}

void page02::on_pushButton_clicked()
{
    //点击翻转到页面1
    //发送信号出去
    emit page02Clicked();
}

void page02::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    //使用 Qt 的绘图系统在界面上绘制一张图片
    QPixmap pix(":/images/2.png"); //将指定路径的图片加载进来
    p.drawPixmap(QRect(0, 0, 500, 500), pix);//创建了一个矩形区域
}
