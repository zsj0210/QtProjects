#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui
{
    class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void on_btnWinClose_clicked();

    void on_btnWinMenu_clicked();

    void on_btnWinClose_2_clicked();

    void on_btnCancel_clicked();

private:
    Ui::LoginWidget* ui;
};

#endif // LOGINWIDGET_H
