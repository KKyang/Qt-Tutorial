#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->combo_label->setText(QString::number(ui->comboBox->currentIndex())+" "+ui->comboBox->currentText());
    if(ui->listWidget->currentRow()>0)
    ui->list_label->setText(QString::number(ui->listWidget->currentRow())+" "+ui->listWidget->currentItem()->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->combo_label->setText(QString::number(index)+" "+ui->comboBox->currentText());
}



void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->list_label->setText(QString::number(currentRow)+" "+ui->listWidget->currentItem()->text());
}
