#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qmyselfvideowidget.h"
#include <QMediaPlaylist>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QMediaPlayer* player; //视频播放器
    QString drtTime; //视频文件时间总长度
    QString posTime; //播放视频当前位置

private slots:
    void onstatebuttonchanged(QMediaPlayer::State state); //按钮状态的改变
    void ondrttimechanged(qint64 drt); //视频文件时间长度，更新变化
    void onpostimechanged(qint64 pos); //播放视频当前位置时间，更新变化



    void on_pushButton_open_clicked();

    void on_pushButton_player_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_volume_clicked();

    void on_horizontalSlider_volumeSpeed_valueChanged(int value);

    void on_horizontalSlider_position_valueChanged(int value);

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
