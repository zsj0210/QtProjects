#ifndef PAGE01_H
#define PAGE01_H

#include <QWidget>

namespace Ui
{
    class page01;
}

class page01 : public QWidget
{
    Q_OBJECT

public:
    explicit page01(QWidget *parent = nullptr);
    ~page01();

private slots:
    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void page01Clicked();

private:
    Ui::page01* ui;
};

#endif // PAGE01_H
