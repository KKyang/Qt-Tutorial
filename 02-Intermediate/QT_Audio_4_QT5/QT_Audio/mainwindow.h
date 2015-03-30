#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QAudio>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlaylist>

#include <QUrl>
#include <QString>
#include <QFileDialog>
#include <QStandardPaths>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void play_song();
    
private slots:
    void show_playback_time(const qint64 times);

    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();


    void on_horizontalSlider_song_position_sliderReleased();



    void on_horizontalSlider_sound_valueChanged(int value);

    void on_actionLoad_triggered();

    void on_checkBox_repeat_one_song_clicked(bool checked);

private:
    QString fileName;
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QFont F;

    bool canPause;
    bool canRepeat;

    qint64 playBackTime;
    qint64 playBackSec;
    QString timing;

};

#endif // MAINWINDOW_H
