#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void replay_or_not();
    void song_loaded_play_song();
    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();

    void on_checkBox_repeat_one_song_clicked(bool checked);

    void on_actionLoad_triggered();

private:
    QString fileName;
    QFileInfo info;
    Ui::MainWindow *ui;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;


    bool canPause;
    bool canRepeat;

    qint64 playBackTime;
    qint64 playBackSec;
    QString timing;
};

#endif // MAINWINDOW_H
