/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_pre;
    QPushButton *pushButton_next;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_2;
    QSlider *horizontalSlider_playSpeed;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(662, 409);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/0.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 641, 371));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout->addWidget(groupBox);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_open = new QPushButton(layoutWidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/1.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_open->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_open);

        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/4.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_play->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_play);

        pushButton_pause = new QPushButton(layoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/5.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pause->setIcon(icon3);

        horizontalLayout->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(layoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/6.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_pre = new QPushButton(layoutWidget);
        pushButton_pre->setObjectName(QString::fromUtf8("pushButton_pre"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/7.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pre->setIcon(icon5);

        horizontalLayout->addWidget(pushButton_pre);

        pushButton_next = new QPushButton(layoutWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/8.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon6);

        horizontalLayout->addWidget(pushButton_next);

        pushButton_volume = new QPushButton(layoutWidget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_volume->setIcon(icon7);

        horizontalLayout->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(layoutWidget);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        horizontalSlider_volume->setMaximum(100);
        horizontalSlider_volume->setValue(50);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_volume);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_2->addWidget(label_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_time = new QLabel(layoutWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));

        horizontalLayout_2->addWidget(label_time);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalSlider_playSpeed = new QSlider(layoutWidget);
        horizontalSlider_playSpeed->setObjectName(QString::fromUtf8("horizontalSlider_playSpeed"));
        horizontalSlider_playSpeed->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_playSpeed);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MP3\351\237\263\351\242\221\346\222\255\346\224\276\345\231\250--\346\265\213\350\257\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\210\227\350\241\250", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_play->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        pushButton_pre->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButton_next->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton_volume->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\220\215\347\247\260\357\274\232", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\350\277\233\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
