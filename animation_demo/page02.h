#ifndef PAGE02_H
#define PAGE02_H

#include <QWidget>

namespace Ui
{
    class page02;
}

class page02 : public QWidget
{
    Q_OBJECT

public:
    explicit page02(QWidget *parent = nullptr);
    ~page02();

private slots:
    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void page02Clicked();

private:
    Ui::page02* ui;
};

#endif // PAGE02_H
