#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    animation_temp = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//平移
void MainWindow::on_pushButton_translation_clicked()
{
    animation_temp = 1;
    update();
}

//旋转
void MainWindow::on_pushButton_rotate_clicked()
{
    animation_temp = 2;
    update();
}

//自定义控件的绘制
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    if(animation_temp == 1)
    {
        //平移
        QTransform transform;
        transform.translate(30, 10);
        p.setTransform(transform);
    }
    else if(animation_temp == 2)
    {
        //旋转
        QTransform transform;
        transform.translate(width() / 2, 0);
        transform.rotate(45, Qt::YAxis);
        p.setTransform(transform);
    }

    //使用 Qt 的绘图系统在界面上绘制一张图片
    QPixmap pix(":/images/1.png"); //将指定路径的图片加载进来
    p.drawPixmap(QRect(0, 0, 500, 500), pix);//创建了一个矩形区域
}







