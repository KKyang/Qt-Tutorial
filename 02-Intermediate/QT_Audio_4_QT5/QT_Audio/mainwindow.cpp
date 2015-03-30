#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    F.setPointSize(20);
    canPause = false;
    canRepeat = false;


    ui->label__sound_volume->setText(QString::number(ui->horizontalSlider_sound->value()));

    player->setVolume(ui->horizontalSlider_sound->value());

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(show_playback_time(qint64)));
    connect(this,SIGNAL(play_song()),this,SLOT(on_pushButton_play_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_play_clicked()
{
    if(!canPause&&player->isAvailable())
    {
        ui->horizontalSlider_song_position->setMinimum(0);
        ui->horizontalSlider_song_position->setMaximum(player->duration());
        ui->label_song_name->setFont(F);
        ui->label_song_name->setText(player->metaData(QMediaMetaData::Title).toString().toUtf8());
        canPause=true;
        player->play();
    }
    else if(canPause)
    {
        player->pause();
        canPause=false;
    }

}

void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
    canPause=false;

}

void MainWindow::show_playback_time(const qint64 times)
{
    timing.clear();
    playBackTime=times/60000;
    playBackSec=(times%60000)/1000;


    if(playBackTime>9)
    {
        timing=QString::number(playBackTime);
    }
    else if(playBackTime<10&&playBackTime>0)
    {
        timing="0"+QString::number(playBackTime);
    }
    else
    {
        timing="00";
    }
    timing=timing+":";
    if(playBackSec>9)
    {
        timing=timing+QString::number(playBackSec);
    }
    else if(playBackSec<10&&playBackSec>0)
    {
        timing=timing+"0"+QString::number(playBackSec);
    }
    else
    {
        timing=timing+"00";
    }



    ui->label_show_time->setText(timing);
    qDebug()<<QString::number(times);
    ui->horizontalSlider_song_position->setValue(times);

    if(times==player->duration())
    {
        player->setPosition(0);
        canPause=false;
        if(canRepeat)
        {
            player->pause();
            player->play();
        }
    }
}

void MainWindow::on_horizontalSlider_song_position_sliderReleased()
{
    player->setPosition(ui->horizontalSlider_song_position->value());
}



void MainWindow::on_horizontalSlider_sound_valueChanged(int value)
{
    player->setVolume(value);
    ui->label__sound_volume->setText(QString::number(value));
}

void MainWindow::on_actionLoad_triggered()
{
    if(player->availability())
        player->stop();
    fileName.clear();
    fileName=QFileDialog::getOpenFileName(this,tr("Open mp3"),QStandardPaths::writableLocation(QStandardPaths::MusicLocation),tr("mp3(*.mp3)")).toUtf8();
    player->setMedia(QUrl::fromLocalFile(fileName.toUtf8()));
    canPause=false;

    ui->horizontalSlider_song_position->setMinimum(0);
    ui->horizontalSlider_song_position->setMaximum(player->duration());
    ui->label_song_name->setFont(F);
    ui->label_song_name->setText(player->metaData(QMediaMetaData::Title).toString().toUtf8());
    //emit play_song();
}






void MainWindow::on_checkBox_repeat_one_song_clicked(bool checked)
{
    if(checked)
    {
        canRepeat = true;
    }
    else
    {
        canRepeat = false;
    }
}
