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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qmyselfvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMyselfVideoWidget *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_open;
    QPushButton *pushButton_player;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volumeSpeed;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer_3;
    QSlider *horizontalSlider_position;
    QLabel *label_speed;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(615, 370);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/11.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QMyselfVideoWidget(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 591, 251));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 270, 591, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_open = new QPushButton(widget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/1.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_open->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButton_open);

        pushButton_player = new QPushButton(widget);
        pushButton_player->setObjectName(QString::fromUtf8("pushButton_player"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/4.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_player->setIcon(icon2);

        horizontalLayout_3->addWidget(pushButton_player);

        pushButton_pause = new QPushButton(widget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/5.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pause->setIcon(icon3);

        horizontalLayout_3->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/6.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon4);

        horizontalLayout_3->addWidget(pushButton_stop);

        pushButton_volume = new QPushButton(widget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_volume->setIcon(icon5);

        horizontalLayout_3->addWidget(pushButton_volume);

        horizontalSlider_volumeSpeed = new QSlider(widget);
        horizontalSlider_volumeSpeed->setObjectName(QString::fromUtf8("horizontalSlider_volumeSpeed"));
        horizontalSlider_volumeSpeed->setMaximum(99);
        horizontalSlider_volumeSpeed->setValue(50);
        horizontalSlider_volumeSpeed->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_volumeSpeed);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_name = new QLabel(widget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_4->addWidget(label_name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalSlider_position = new QSlider(widget);
        horizontalSlider_position->setObjectName(QString::fromUtf8("horizontalSlider_position"));
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_position);

        label_speed = new QLabel(widget);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));

        horizontalLayout_4->addWidget(label_speed);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MP4\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250--\346\265\213\350\257\225", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_player->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        pushButton_volume->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\345\220\215\347\247\260\357\274\232", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\222\255\346\224\276\350\277\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
