#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_danny_radioButton_clicked()
{
    if(ui->danny_radioButton->isChecked())
        ui->res_choice->setText("Danny's");
}

void MainWindow::on_ham_radioButton_clicked()
{
    if(ui->ham_radioButton->isChecked())
        ui->res_choice->setText("Ham");
}

void MainWindow::on_money_checkBox_toggled(bool checked)
{
    if(checked)
        ui->money_pre->setText("Prepared!!");
    else
        ui->money_pre->setText("Not prepared.");
}

void MainWindow::on_credit_checkBox_toggled(bool checked)
{
    if(checked)
        ui->credit_pre->setText("Prepared!!");
    else
        ui->credit_pre->setText("Not prepared.");
}
