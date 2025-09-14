/********************************************************************************
** Form generated from reading UI file 'page01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE01_H
#define UI_PAGE01_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page01
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *page01)
    {
        if (page01->objectName().isEmpty())
            page01->setObjectName(QString::fromUtf8("page01"));
        page01->resize(500, 500);
        pushButton = new QPushButton(page01);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 80, 20));

        retranslateUi(page01);

        QMetaObject::connectSlotsByName(page01);
    } // setupUi

    void retranslateUi(QWidget *page01)
    {
        page01->setWindowTitle(QCoreApplication::translate("page01", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("page01", "\351\241\265\351\235\2421", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page01: public Ui_page01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE01_H
