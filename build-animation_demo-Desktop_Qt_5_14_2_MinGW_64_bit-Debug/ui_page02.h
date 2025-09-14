/********************************************************************************
** Form generated from reading UI file 'page02.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE02_H
#define UI_PAGE02_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page02
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *page02)
    {
        if (page02->objectName().isEmpty())
            page02->setObjectName(QString::fromUtf8("page02"));
        page02->resize(500, 500);
        pushButton = new QPushButton(page02);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 40, 80, 20));

        retranslateUi(page02);

        QMetaObject::connectSlotsByName(page02);
    } // setupUi

    void retranslateUi(QWidget *page02)
    {
        page02->setWindowTitle(QCoreApplication::translate("page02", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("page02", "\351\241\265\351\235\2422", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page02: public Ui_page02 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE02_H
