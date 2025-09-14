#ifndef ANIMATIONDIALOG_H
#define ANIMATIONDIALOG_H
#include "animationstackwidget.h"
#include "page01.h"
#include "page02.h"

#include <QDialog>


class animationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit animationDialog(QWidget *parent = nullptr);
    ~animationDialog();

private:
    animationStackWidget* m_asw;
    page01* m_page01;
    page02* m_page02;

private slots:
    void onpage01Clicked();
    void onpage02Clicked();

};

#endif // ANIMATIONDIALOG_H
