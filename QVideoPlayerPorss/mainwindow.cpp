#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    player->setNotifyInterval(1000); //信息更新周期
    player->setVideoOutput(ui->graphicsView); //视频播放组件
    ui->graphicsView->SetMediaPalyer(player); //设置显示组件的关联播放器

    connect(player, QOverload<QMediaPlayer::State>::of(&QMediaPlayer::stateChanged),
            this, &MainWindow::onstatebuttonchanged);

    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::ondrttimechanged);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::onpostimechanged);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onstatebuttonchanged(QMediaPlayer::State state) //按钮状态的改变
{
    ui->pushButton_player->setEnabled(!(state == QMediaPlayer::PlayingState));
    ui->pushButton_pause->setEnabled((state == QMediaPlayer::PlayingState));
    ui->pushButton_stop->setEnabled((state == QMediaPlayer::PlayingState));
}

void MainWindow::ondrttimechanged(qint64 drt) //视频文件时间长度，更新变化
{
    ui->horizontalSlider_position->setMaximum(drt);

    int sec = drt / 1000; //秒
    int min = sec / 60; //分
    sec = sec % 60; //余数秒

    drtTime = QString::asprintf("%d:%d", min, sec);
    ui->label_speed->setText(posTime + "/" + drtTime);
}

void MainWindow::onpostimechanged(qint64 pos) //播放视频当前位置时间，更新变化
{
    if(ui->horizontalSlider_position->isSliderDown())
        return;

    ui->horizontalSlider_position->setSliderPosition(pos);

    int sec = pos / 1000; //秒
    int min = sec / 60; //分
    sec = sec % 60; //余数秒

    posTime = QString::asprintf("%d:%d", min, sec);
    ui->label_speed->setText(posTime + "/" + drtTime);

}

//打开文件
void MainWindow::on_pushButton_open_clicked()
{
    QString currentpath = QDir::homePath(); //获取系统当前目录地址
    QString dlgtitle = "请选择视频文件：";
    QString filter = "所有文件(*.*);;mp4文件(*.mp4)"; //文件过滤器
    QString strfile = QFileDialog::getOpenFileName(this, dlgtitle, currentpath, filter);

    if(strfile.isEmpty())
        return;

    QFileInfo fileinfo(strfile);
    ui->label_name->setText(fileinfo.fileName());

    player->setMedia(QUrl::fromLocalFile(strfile));
    player->play();
}

//播放
void MainWindow::on_pushButton_player_clicked()
{
    player->play();
}

//暂停
void MainWindow::on_pushButton_pause_clicked()
{
    player->pause();
}

//停止
void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
}

//音量
void MainWindow::on_pushButton_volume_clicked()
{
    bool bmute = player->isMuted();
    player->setMuted(!bmute);

    if(bmute)
        ui->pushButton_volume->setIcon(QIcon(":/new/prefix1/images/volumn.bmp"));
    else
        ui->pushButton_volume->setIcon(QIcon(":/new/prefix1/images/mute.bmp"));
}


//控制音量
void MainWindow::on_horizontalSlider_volumeSpeed_valueChanged(int value)
{
    player->setVolume(value);
}

//控制播放进度
void MainWindow::on_horizontalSlider_position_valueChanged(int value)
{
    player->setPosition(value);
}
