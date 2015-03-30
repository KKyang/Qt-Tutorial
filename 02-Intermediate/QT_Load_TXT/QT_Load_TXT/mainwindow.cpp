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



void MainWindow::on_read_file_button_clicked()
{
    inputFile.setFileName("input.txt");
    if(inputFile.exists())
    {
        if(inputFile.open(QIODevice::ReadOnly))
        {
            in.setDevice(&inputFile);
            while(!in.atEnd())
            {
                line.clear();
                line = in.readLine();          //readLine(int) (max 75)
                ui->message->append(line);
            }
        }
        inputFile.close();
    }
    else
        QMessageBox::warning(0, 0, "NO TEXT FILE FOUND!!");

}
