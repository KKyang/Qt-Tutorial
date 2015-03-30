#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("This is a status bar.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action1_triggered()
{
    ui->number_label->setText("1");
    ui->statusBar->showMessage("1");
}

void MainWindow::on_action2_triggered()
{
    ui->number_label->setText("2");
    ui->statusBar->showMessage("2");
}

void MainWindow::on_action3_triggered()
{
    ui->number_label->setText("3");
    ui->statusBar->showMessage("3");
}

void MainWindow::on_actionToolBar1_triggered()
{
    on_action1_triggered();
}

void MainWindow::on_actionToolBar2_triggered()
{
    on_action2_triggered();
}

void MainWindow::on_actionToolBar3_triggered()
{
    on_action3_triggered();
}
