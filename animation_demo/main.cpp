#include "mainwindow.h"
#include "animationdialog.h"

#include <QApplication>

int main(int argc, char* argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    animationDialog animationdialog;
    animationdialog.show();

    return a.exec();
}
