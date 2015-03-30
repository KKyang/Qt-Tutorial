#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QMutex>
#include "dialog/dialogimageresize.h"
#include "dialog/dialoghistogram.h"
#include "dialog/dialogblur.h"
#include "dialog/dialogadjust64.h"
#include "mymat.h"
#include "myblur.h"

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
    void on_actionLoad_BMP_Files_triggered();

    void on_actionSave_BMP_Image_Using_QImage_triggered();

    void on_actionSave_BMP_Image_Using_fstream_triggered();

    void on_actionResize_triggered();

    void on_actionHistogram_triggered();

    void on_actionGrayscale_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBlur_triggered();

    void on_actionLoad_64_Files_triggered();

    void on_actionAdjust_64_triggered();

    void receiveLightness(int);
    void disconnectLightness();
private:
    QString saveImage();
    void refreshImage();

    Ui::MainWindow *ui;
    std::string fileName;
    myCV::myMat image;
    myCV::myMat undo;
    myCV::myMat redo;
    QImage test;

    DialogAdjust64 *adj;
    QMutex locker;
};

#endif // MAINWINDOW_H
