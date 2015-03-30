#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect menu bar exit button to exitCheck slot
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(exitCheck()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_message_clicked()
{
    QMessageBox::information(this,"Information","This is a message box.");
}

void MainWindow::exitCheck()
{
    //check if a user want to exit the app
    if(QMessageBox::warning(this, "Warning", "Do you want to exit?", QMessageBox::Yes|QMessageBox::No,QMessageBox::No)==QMessageBox::Yes)
    {
        //close mainwindow
        close();
    }
}
