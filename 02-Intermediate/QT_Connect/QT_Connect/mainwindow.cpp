#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection = 0;
    connection = new connects;
    connect(this,SIGNAL(send_signal(bool)),connection,SLOT(get_signal(bool)));
    connect(connection,SIGNAL(send_number(int)),this,SLOT(get_feedback_signal(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_send_signal_1_clicked()
{
    send_signal(1);
}

void MainWindow::on_pushButton_send_signal_0_clicked()
{
    send_signal(0);
}

void MainWindow::get_feedback_signal(int count)
{
    ui->label_show_feedback_int->setText(QString::number(count));
}


//***For non-Qt variables***//
/*
 * 1. Register it:
 * qRegisterMetaType<cv::Mat>("cv::Mat");
 * 2. Then connect
 * connect(...);
 *
 * Note: Other ways to register:
 * typedef QVector<QVector<int>> MyArray;
 * qRegisterMetaType<MyArray>("MyArray");
 */
