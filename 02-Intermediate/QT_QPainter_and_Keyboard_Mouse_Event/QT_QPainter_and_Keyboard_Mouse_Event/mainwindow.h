#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include <QMainWindow>
#include <QPainter>
#include <QEvent>
#include"myqlabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);


public slots:
    void setMouseValue(int x,int y);

private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    QPixmap *pix;

    QPainter *painter;
    QPainterPath *path;
};

#endif // MAINWINDOW_H
