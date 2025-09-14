#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QFile>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint); //去掉标题
    this->setAttribute(Qt::WA_TranslucentBackground); //使窗口边框空白部分透明

    QFile file(":/new/qss/resource/qss/default.css");
    file.open(QIODevice::ReadOnly);

    //设置样式表
    qApp->setStyleSheet(file.readAll());
    file.close();

    ui->stackedWidget->setCurrentIndex(0);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_btnWinClose_clicked()
{
    this->close();
}
void LoginWidget::on_btnWinClose_2_clicked()
{
    this->close();
}

//页面1的翻转动作
void LoginWidget::on_btnWinMenu_clicked()
{
    ui->stackedWidget->setstartVal(0); //翻转的起始值
    ui->stackedWidget->setendVal(180); //翻转的结束值

    //m_asw实现动画效果
    ui->stackedWidget->animation(1);

}

//页面2的翻转动作
void LoginWidget::on_btnCancel_clicked()
{
    ui->stackedWidget->setstartVal(0); //翻转的起始值
    ui->stackedWidget->setendVal(-180); //翻转的结束值

    //m_asw实现动画效果
    ui->stackedWidget->animation(0);
}
