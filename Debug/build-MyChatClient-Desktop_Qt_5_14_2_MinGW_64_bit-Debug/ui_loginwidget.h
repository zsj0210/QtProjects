/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <animationstackwidget.h>
#include "clineedit.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    animationStackWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetWinTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWinIcon;
    QLabel *labelWinTitle;
    QPushButton *btnWinMenu;
    QPushButton *btnWinMin;
    QPushButton *btnWinClose;
    QWidget *widgetBody;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelWeclcom;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelUserHead;
    QWidget *widgetInput;
    QVBoxLayout *verticalLayout_3;
    QIconLineEdit *lineEditUser;
    QIconLineEdit *lineEditPasswd;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxPasswd;
    QCheckBox *checkBoxAutoLogin;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnLogin;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_9;
    QWidget *widgetWinTitle_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelWinTitle_2;
    QPushButton *btnWinMin_2;
    QPushButton *btnWinClose_2;
    QWidget *widgetBody_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout;
    QLabel *label_3;
    QIPLineEdit *lineEditHostAddr;
    QLabel *label_4;
    QLineEdit *lineEditHostMsgPort;
    QLabel *label_5;
    QLineEdit *lineEditHostFilePort;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSaveCfg;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(385, 306);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/background/app.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWidget->setWindowIcon(icon);
        LoginWidget->setStyleSheet(QString::fromUtf8("QWidget#page, QWidget#page_2 {\n"
"	border: 1px solid #A5A6A8;\n"
"	border-radius: 4px;\n"
"}"));
        stackedWidget = new animationStackWidget(LoginWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 370, 286));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        widgetWinTitle = new QWidget(page);
        widgetWinTitle->setObjectName(QString::fromUtf8("widgetWinTitle"));
        widgetWinTitle->setMinimumSize(QSize(0, 30));
        widgetWinTitle->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(widgetWinTitle);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labelWinIcon = new QLabel(widgetWinTitle);
        labelWinIcon->setObjectName(QString::fromUtf8("labelWinIcon"));
        labelWinIcon->setMinimumSize(QSize(30, 30));
        labelWinIcon->setMaximumSize(QSize(30, 30));
        labelWinIcon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resource/images/robot.png")));

        horizontalLayout_2->addWidget(labelWinIcon);

        labelWinTitle = new QLabel(widgetWinTitle);
        labelWinTitle->setObjectName(QString::fromUtf8("labelWinTitle"));
        labelWinTitle->setStyleSheet(QString::fromUtf8("color: #FFFFFF;"));

        horizontalLayout_2->addWidget(labelWinTitle);

        btnWinMenu = new QPushButton(widgetWinTitle);
        btnWinMenu->setObjectName(QString::fromUtf8("btnWinMenu"));
        btnWinMenu->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resource/common/ic_login_cfg.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinMenu->setIcon(icon1);

        horizontalLayout_2->addWidget(btnWinMenu);

        btnWinMin = new QPushButton(widgetWinTitle);
        btnWinMin->setObjectName(QString::fromUtf8("btnWinMin"));
        btnWinMin->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/resource/common/ic_min_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinMin->setIcon(icon2);

        horizontalLayout_2->addWidget(btnWinMin);

        btnWinClose = new QPushButton(widgetWinTitle);
        btnWinClose->setObjectName(QString::fromUtf8("btnWinClose"));
        btnWinClose->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/resource/common/ic_close_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinClose->setIcon(icon3);

        horizontalLayout_2->addWidget(btnWinClose);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addWidget(widgetWinTitle);

        widgetBody = new QWidget(page);
        widgetBody->setObjectName(QString::fromUtf8("widgetBody"));
        verticalLayout_5 = new QVBoxLayout(widgetBody);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelWeclcom = new QLabel(widgetBody);
        labelWeclcom->setObjectName(QString::fromUtf8("labelWeclcom"));
        labelWeclcom->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resource/background/logo.jpg")));
        labelWeclcom->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelWeclcom);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(40, 20, 40, 20);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelUserHead = new QLabel(widgetBody);
        labelUserHead->setObjectName(QString::fromUtf8("labelUserHead"));
        labelUserHead->setMinimumSize(QSize(82, 82));
        labelUserHead->setMaximumSize(QSize(82, 82));
        labelUserHead->setStyleSheet(QString::fromUtf8("QLabel#labelUserHead {\n"
"	border: 1px solid #C9C9C9;\n"
"}"));
        labelUserHead->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resource/head/head-64.png")));
        labelUserHead->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelUserHead);

        widgetInput = new QWidget(widgetBody);
        widgetInput->setObjectName(QString::fromUtf8("widgetInput"));
        verticalLayout_3 = new QVBoxLayout(widgetInput);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditUser = new QIconLineEdit(widgetInput);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));
        lineEditUser->setMinimumSize(QSize(0, 25));
        lineEditUser->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(lineEditUser);

        lineEditPasswd = new QIconLineEdit(widgetInput);
        lineEditPasswd->setObjectName(QString::fromUtf8("lineEditPasswd"));
        lineEditPasswd->setMinimumSize(QSize(0, 25));
        lineEditPasswd->setMaximumSize(QSize(16777215, 25));
        lineEditPasswd->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(lineEditPasswd);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxPasswd = new QCheckBox(widgetInput);
        checkBoxPasswd->setObjectName(QString::fromUtf8("checkBoxPasswd"));
        checkBoxPasswd->setChecked(true);

        horizontalLayout->addWidget(checkBoxPasswd);

        checkBoxAutoLogin = new QCheckBox(widgetInput);
        checkBoxAutoLogin->setObjectName(QString::fromUtf8("checkBoxAutoLogin"));
        checkBoxAutoLogin->setChecked(false);

        horizontalLayout->addWidget(checkBoxAutoLogin);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(widgetInput);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnLogin = new QPushButton(widgetBody);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(btnLogin);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addWidget(widgetBody);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_9 = new QVBoxLayout(page_2);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 1, 1, 1);
        widgetWinTitle_2 = new QWidget(page_2);
        widgetWinTitle_2->setObjectName(QString::fromUtf8("widgetWinTitle_2"));
        widgetWinTitle_2->setMinimumSize(QSize(0, 30));
        widgetWinTitle_2->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_5 = new QHBoxLayout(widgetWinTitle_2);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 0, 0, 0);
        labelWinTitle_2 = new QLabel(widgetWinTitle_2);
        labelWinTitle_2->setObjectName(QString::fromUtf8("labelWinTitle_2"));
        labelWinTitle_2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;"));

        horizontalLayout_5->addWidget(labelWinTitle_2);

        btnWinMin_2 = new QPushButton(widgetWinTitle_2);
        btnWinMin_2->setObjectName(QString::fromUtf8("btnWinMin_2"));
        btnWinMin_2->setFocusPolicy(Qt::NoFocus);
        btnWinMin_2->setIcon(icon2);

        horizontalLayout_5->addWidget(btnWinMin_2);

        btnWinClose_2 = new QPushButton(widgetWinTitle_2);
        btnWinClose_2->setObjectName(QString::fromUtf8("btnWinClose_2"));
        btnWinClose_2->setFocusPolicy(Qt::NoFocus);
        btnWinClose_2->setIcon(icon3);

        horizontalLayout_5->addWidget(btnWinClose_2);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout_9->addWidget(widgetWinTitle_2);

        widgetBody_2 = new QWidget(page_2);
        widgetBody_2->setObjectName(QString::fromUtf8("widgetBody_2"));
        verticalLayout_6 = new QVBoxLayout(widgetBody_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(widgetBody_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditHostAddr = new QIPLineEdit(groupBox);
        lineEditHostAddr->setObjectName(QString::fromUtf8("lineEditHostAddr"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditHostAddr);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        lineEditHostMsgPort = new QLineEdit(groupBox);
        lineEditHostMsgPort->setObjectName(QString::fromUtf8("lineEditHostMsgPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditHostMsgPort);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lineEditHostFilePort = new QLineEdit(groupBox);
        lineEditHostFilePort->setObjectName(QString::fromUtf8("lineEditHostFilePort"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditHostFilePort);


        horizontalLayout_6->addLayout(formLayout);


        verticalLayout_7->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout_6->addWidget(groupBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        btnCancel = new QPushButton(widgetBody_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_7->addWidget(btnCancel);

        btnSaveCfg = new QPushButton(widgetBody_2);
        btnSaveCfg->setObjectName(QString::fromUtf8("btnSaveCfg"));

        horizontalLayout_7->addWidget(btnSaveCfg);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_9->addWidget(widgetBody_2);

        stackedWidget->addWidget(page_2);

        retranslateUi(LoginWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        labelWinIcon->setText(QString());
        labelWinTitle->setText(QString());
        btnWinMenu->setText(QString());
        btnWinMin->setText(QString());
        btnWinClose->setText(QString());
        labelWeclcom->setText(QString());
        labelUserHead->setText(QString());
        lineEditUser->setText(QCoreApplication::translate("LoginWidget", "xiaoni", nullptr));
        lineEditUser->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEditPasswd->setText(QCoreApplication::translate("LoginWidget", "1234", nullptr));
        lineEditPasswd->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        checkBoxPasswd->setText(QCoreApplication::translate("LoginWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBoxAutoLogin->setText(QCoreApplication::translate("LoginWidget", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        btnLogin->setToolTip(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLogin->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        labelWinTitle_2->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225\351\205\215\347\275\256", nullptr));
        btnWinMin_2->setText(QString());
        btnWinClose_2->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("LoginWidget", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\351\205\215\347\275\256\357\274\232", nullptr));
        lineEditHostAddr->setText(QCoreApplication::translate("LoginWidget", "192.168.5.181", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWidget", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEditHostMsgPort->setText(QCoreApplication::translate("LoginWidget", "60001", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWidget", "\346\226\207\344\273\266\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEditHostFilePort->setText(QCoreApplication::translate("LoginWidget", "60002", nullptr));
        btnCancel->setText(QCoreApplication::translate("LoginWidget", "\345\217\226\346\266\210", nullptr));
        btnSaveCfg->setText(QCoreApplication::translate("LoginWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
