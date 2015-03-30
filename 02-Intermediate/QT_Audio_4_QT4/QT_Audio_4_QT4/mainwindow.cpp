#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mediaObject = new Phonon::MediaObject();
    audioOutput = new Phonon::AudioOutput();

    Phonon::createPath(mediaObject, audioOutput);
    ui->seekSlider->setMediaObject(mediaObject);
    ui->volumeSlider->setAudioOutput(audioOutput);

    canPause = false;
    canRepeat = false;

    connect(mediaObject,SIGNAL(finished()),this,SLOT(replay_or_not()));
    connect(mediaObject,SIGNAL(metaDataChanged()),this,SLOT(song_loaded_play_song()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::song_loaded_play_song()
{
    ui->label_song_name->setText(mediaObject->metaData().value("TITLE").toUtf8());
    if(mediaObject->metaData().value("TITLE").toUtf8() == "")
        ui->label_song_name->setText(info.fileName());
}

void MainWindow::on_pushButton_play_clicked()
{
    if(!canPause&&mediaObject->isValid())
    {
        mediaObject->play();

        canPause=true;
    }
    else if(canPause)
    {
        mediaObject->pause();
        canPause=false;
    }

}

void MainWindow::on_pushButton_stop_clicked()
{
    mediaObject->stop();
    canPause=false;

}





void MainWindow::on_actionLoad_triggered()
{
    if(mediaObject->isValid())
        mediaObject->stop();
    fileName.clear();
    fileName=QFileDialog::getOpenFileName(this,tr("Open mp3"),QDesktopServices::storageLocation(QDesktopServices::MusicLocation),tr("mp3(*.mp3)")).toUtf8();
    mediaObject->setCurrentSource(QUrl::fromLocalFile(fileName.toUtf8()));
    info=fileName;
    canPause=false;



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

void MainWindow::replay_or_not()
{
    if(canRepeat)
    {
        mediaObject->play();
    }
}










