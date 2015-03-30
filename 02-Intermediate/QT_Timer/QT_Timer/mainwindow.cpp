#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Interval = 0;
    ui->doubleSpinBox_timer_interval_setup->setValue(1.00);
    timerCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_start_clicked()
{
    if(ui->pushButton_start->isEnabled())
    {
        if(!Interval)
        {
            Interval = new QTimer(0);
            Interval->setInterval(timerInterval*1000);
            Interval->start();
            connect(Interval,SIGNAL(timeout()),this,SLOT(receive_timer_count()));
        }
        else
        {
            Interval->start();
        }

        ui->pushButton_pause->setEnabled(true);
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_stop->setEnabled(true);
        ui->doubleSpinBox_timer_interval_setup->setEnabled(false);
    }
}



void MainWindow::on_pushButton_pause_clicked()
{
    Interval->stop();
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_start->setEnabled(true);
}

void MainWindow::on_pushButton_stop_clicked()
{
    Interval->stop();
    delete Interval;
    Interval = 0;
    timerCount = 0;
    ui->label_show_count_num->setText(QString::number(timerCount));

    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);
    ui->doubleSpinBox_timer_interval_setup->setEnabled(true);

}

void MainWindow::on_doubleSpinBox_timer_interval_setup_valueChanged(double arg1)
{
    timerInterval = arg1;
}

void MainWindow::receive_timer_count()
{
    timerCount++;
    ui->label_show_count_num->setText(QString::number(timerCount));
}
