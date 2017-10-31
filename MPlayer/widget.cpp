#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    ui->progressBar->setValue(0);

    connect (mMediaPlayer, &QMediaPlayer::positionChanged,[&](qint64 pos){
        ui->progressBar->setValue(pos);
    });

    connect (mMediaPlayer, &QMediaPlayer::durationChanged,[&](qint64 dur){
        ui->progressBar->setMaximum(dur);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open");
    if(file_name.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(file_name));
    mMediaPlayer->setVolume(ui->volumeSlider->value());
    on_playButton_clicked();
}

void Widget::on_playButton_clicked()
{
    mMediaPlayer->play();
}

void Widget::on_pauseButton_clicked()
{
    mMediaPlayer->pause();
}

void Widget::on_stopButton_clicked()
{
    mMediaPlayer->stop();
}

void Widget::on_muteButton_clicked()
{
    if(ui->muteButton->text()=="Mute"){
        mMediaPlayer->setMuted(true);
        ui->muteButton->setText("Unmute");
    }
    else{
        mMediaPlayer->setMuted(false);
        ui->muteButton->setText("Mute");
    }
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}
