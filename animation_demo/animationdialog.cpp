#include "animationdialog.h"

#include <QStackedWidget>
#include <QHBoxLayout>

animationDialog::animationDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(500, 500);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    m_asw = new animationStackWidget(this);
    m_page01 = new page01(this);
    m_page02 = new page02(this);

    m_asw->addWidget(m_page01);
    m_asw->addWidget(m_page02);

    QObject::connect(m_page01, &page01::page01Clicked, this, &animationDialog::onpage01Clicked);
    QObject::connect(m_page02, &page02::page02Clicked, this, &animationDialog::onpage02Clicked);

    layout->addWidget(m_asw);
    this->setLayout(layout);

}

animationDialog::~animationDialog()
{

}

void animationDialog::onpage01Clicked()
{
    m_asw->setstartVal(0); //翻转的起始值
    m_asw->setendVal(180); //翻转的结束值

    //m_asw实现动画效果
    m_asw->animation(1);
}

void animationDialog::onpage02Clicked()
{
    m_asw->setstartVal(0); //翻转的起始值
    m_asw->setendVal(-180); //翻转的结束值

    //m_asw实现动画效果
    m_asw->animation(0);
}
