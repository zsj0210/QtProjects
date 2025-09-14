#include "qmyselfvideowidget.h"

QMyselfVideoWidget::QMyselfVideoWidget(QWidget *parent)
    : QVideoWidget(parent)
{


}

QMyselfVideoWidget::~QMyselfVideoWidget()
{

}

//设置播放器操作
void QMyselfVideoWidget::SetMediaPalyer(QMediaPlayer *player)
{
    theplayer = player;
}

//按esc退出全屏状态
void QMyselfVideoWidget::keyPressEvent(QKeyEvent *event)
{

    if((event->key() == Qt::Key_Escape) && (isFullScreen()))
    {
        setFullScreen(false);
        //调用accept()表示当前的事件处理函数已经处理了这个键盘事件
        event->accept();
        //这通常用于在处理完特定事件后，继续让基类处理其他可能的事件。
        QVideoWidget::keyPressEvent(event);
    }

}

//鼠标控制暂停和播放
void QMyselfVideoWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //如果确认是左键点击，检查媒体播放器 theplayer 的当前状态是否为 PlayingState，即是否正在播放媒体。
        if(theplayer->state() == QMediaPlayer::PlayingState)
            theplayer->pause();
        else
            theplayer->play();
    }

    //这通常用于在自定义处理鼠标事件之前或之后添加额外的行为，同时保留基类的功能。
    QVideoWidget::mousePressEvent(event);
}



