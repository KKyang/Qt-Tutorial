#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    multi = 0;


}

MainWindow::~MainWindow()
{
    if(multi->isRunning())
    {
        multi->stop();
        multi->wait(1000);
        multi->exit();
        delete multi;
        multi = 0;
    }
    delete ui;
}

void MainWindow::on_thread_start_button_clicked()
{
    if(!multi){
        multi = new threads;
        multi->start();
        connect(multi,SIGNAL(send_count_data(int)),this,SLOT(get_count_data(int)));
    }
    else
    {
        multi->start();
    }
    ui->thread_start_button->setEnabled(false);
    ui->thread_stop_button->setEnabled(true);
    ui->thread_reset_button->setEnabled(true);
}

void MainWindow::on_thread_stop_button_clicked()
{
    multi->stop();
    ui->thread_start_button->setEnabled(true);
    ui->thread_stop_button->setEnabled(true);
    ui->thread_reset_button->setEnabled(false);
}

void MainWindow::on_thread_reset_button_clicked()
{
    multi->stop();
    multi->wait(1000);
    multi->exit();
    delete multi;
    multi = 0;
    ui->thread_start_button->setEnabled(true);
    ui->thread_stop_button->setEnabled(false);
    ui->thread_reset_button->setEnabled(false);
    ui->label_show_count->setText(QString::number(0));
}

void MainWindow::get_count_data(int count)
{
    ui->label_show_count->setText(QString::number(count));
}
