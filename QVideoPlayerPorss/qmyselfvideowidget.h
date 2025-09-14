#ifndef QMYSELFVIDEOWIDGET_H
#define QMYSELFVIDEOWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QObject>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QMouseEvent>

class QMyselfVideoWidget : public QVideoWidget
{
public:
    explicit QMyselfVideoWidget(QWidget *parent = nullptr);
    ~QMyselfVideoWidget();

    void SetMediaPalyer(QMediaPlayer *player);

private:
    QMediaPlayer* theplayer;

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

};

#endif // QMYSELFVIDEOWIDGET_H
