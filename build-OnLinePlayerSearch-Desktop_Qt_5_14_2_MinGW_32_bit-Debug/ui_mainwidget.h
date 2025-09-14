/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *pushButton_Name;
    QLineEdit *lineEdit_Search;
    QGroupBox *groupBox;
    QPushButton *pushButton_Search;
    QListWidget *listWidget_Search;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget_History;
    QTextBrowser *textBrowser_Lyric;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_About;
    QPushButton *pushButton_Skin;
    QPushButton *pushButton_Close;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSlider *progressSlider;
    QLabel *label_Time;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Front;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_Playpause;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_Next;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Loopplay;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSlider *VopSlider;
    QLabel *label_Vop;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(858, 540);
        pushButton_Name = new QPushButton(MainWidget);
        pushButton_Name->setObjectName(QString::fromUtf8("pushButton_Name"));
        pushButton_Name->setGeometry(QRect(20, 70, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_Name->setFont(font);
        pushButton_Name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 50);"));
        lineEdit_Search = new QLineEdit(MainWidget);
        lineEdit_Search->setObjectName(QString::fromUtf8("lineEdit_Search"));
        lineEdit_Search->setGeometry(QRect(190, 70, 431, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        lineEdit_Search->setFont(font1);
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 821, 61));
        pushButton_Search = new QPushButton(groupBox);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));
        pushButton_Search->setGeometry(QRect(620, 10, 161, 41));
        pushButton_Search->setFont(font);
        pushButton_Search->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 50);"));
        listWidget_Search = new QListWidget(MainWidget);
        listWidget_Search->setObjectName(QString::fromUtf8("listWidget_Search"));
        listWidget_Search->setGeometry(QRect(20, 170, 241, 321));
        listWidget_Search->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_Search->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 50);"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 140, 91, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(MainWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 821, 371));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 10, 91, 21));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(570, 10, 131, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        listWidget_History = new QListWidget(groupBox_2);
        listWidget_History->setObjectName(QString::fromUtf8("listWidget_History"));
        listWidget_History->setGeometry(QRect(570, 40, 241, 321));
        listWidget_History->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_History->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 50);"));
        textBrowser_Lyric = new QTextBrowser(groupBox_2);
        textBrowser_Lyric->setObjectName(QString::fromUtf8("textBrowser_Lyric"));
        textBrowser_Lyric->setGeometry(QRect(270, 40, 281, 321));
        textBrowser_Lyric->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        textBrowser_Lyric->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 50);"));
        layoutWidget = new QWidget(MainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(690, 0, 146, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_About = new QPushButton(layoutWidget);
        pushButton_About->setObjectName(QString::fromUtf8("pushButton_About"));
        pushButton_About->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_About->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_About->setIcon(icon);
        pushButton_About->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_About);

        pushButton_Skin = new QPushButton(layoutWidget);
        pushButton_Skin->setObjectName(QString::fromUtf8("pushButton_Skin"));
        pushButton_Skin->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Skin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Skin->setIcon(icon1);
        pushButton_Skin->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_Skin);

        pushButton_Close = new QPushButton(layoutWidget);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Close->setIcon(icon2);
        pushButton_Close->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_Close);

        layoutWidget1 = new QWidget(MainWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 530, 801, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        progressSlider = new QSlider(layoutWidget1);
        progressSlider->setObjectName(QString::fromUtf8("progressSlider"));
        progressSlider->setCursor(QCursor(Qt::PointingHandCursor));
        progressSlider->setMaximum(100);
        progressSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(progressSlider);

        label_Time = new QLabel(layoutWidget1);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setFont(font2);
        label_Time->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_Time);

        layoutWidget2 = new QWidget(MainWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 560, 801, 42));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_Front = new QPushButton(layoutWidget2);
        pushButton_Front->setObjectName(QString::fromUtf8("pushButton_Front"));
        pushButton_Front->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Front->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/pre-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Front->setIcon(icon3);
        pushButton_Front->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_Front);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_Playpause = new QPushButton(layoutWidget2);
        pushButton_Playpause->setObjectName(QString::fromUtf8("pushButton_Playpause"));
        pushButton_Playpause->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Playpause->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/pase-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Playpause->setIcon(icon4);
        pushButton_Playpause->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_Playpause);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_Next = new QPushButton(layoutWidget2);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));
        pushButton_Next->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Next->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/next-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Next->setIcon(icon5);
        pushButton_Next->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_Next);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_Loopplay = new QPushButton(layoutWidget2);
        pushButton_Loopplay->setObjectName(QString::fromUtf8("pushButton_Loopplay"));
        pushButton_Loopplay->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Loopplay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/loop-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Loopplay->setIcon(icon6);
        pushButton_Loopplay->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_Loopplay);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        VopSlider = new QSlider(layoutWidget2);
        VopSlider->setObjectName(QString::fromUtf8("VopSlider"));
        VopSlider->setCursor(QCursor(Qt::PointingHandCursor));
        VopSlider->setMaximum(100);
        VopSlider->setValue(30);
        VopSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(VopSlider);

        label_Vop = new QLabel(layoutWidget2);
        label_Vop->setObjectName(QString::fromUtf8("label_Vop"));
        label_Vop->setFont(font2);
        label_Vop->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_Vop);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_2->raise();
        groupBox->raise();
        pushButton_Name->raise();
        lineEdit_Search->raise();
        listWidget_Search->raise();
        label->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        pushButton_Name->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        lineEdit_Search->setText(QCoreApplication::translate("MainWidget", "\347\245\235\344\275\240\344\270\200\350\267\257\351\241\272\351\243\216", nullptr));
        groupBox->setTitle(QString());
        pushButton_Search->setText(QCoreApplication::translate("MainWidget", "\346\220\234 \347\264\242...", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWidget", "\346\255\214\346\233\262\346\255\214\350\257\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "\346\222\255\346\224\276\346\255\214\346\233\262\347\227\225\350\277\271", nullptr));
        pushButton_About->setText(QString());
        pushButton_Skin->setText(QString());
        pushButton_Close->setText(QString());
        label_Time->setText(QCoreApplication::translate("MainWidget", "00:00", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Front->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\212\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Front->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Playpause->setToolTip(QCoreApplication::translate("MainWidget", "\346\222\255\346\224\276|\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Playpause->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Next->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\213\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Next->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Loopplay->setToolTip(QCoreApplication::translate("MainWidget", "\345\276\252\347\216\257\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Loopplay->setText(QString());
        label_Vop->setText(QCoreApplication::translate("MainWidget", "000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
