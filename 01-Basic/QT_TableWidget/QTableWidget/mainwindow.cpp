#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

//Setup the Table Widget-- lifeTable
    //setup row and column count
    ui->tableWidget->setRowCount(24);
    ui->tableWidget->setColumnCount(24);
    //setup a cell's size
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);
    //prevent user from changing the size of a table cell
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);


    for(int i=0;i<rand()%454+30;i++)
    {
        int x=rand()%24;
        int y=rand()%24;
        if(ui->tableWidget->item(x,y))
        {
            i--;
        }
        else
            ui->tableWidget->setItem(x,y,new QTableWidgetItem("O"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_random_clicked()
{
    ui->tableWidget->clear();

    for(int i=0;i<rand()%454+30;i++)
    {
        int x=rand()%24;
        int y=rand()%24;
        if(ui->tableWidget->item(x,y))
        {
            i--;
        }
        else
            ui->tableWidget->setItem(x,y,new QTableWidgetItem("O"));
    }
}
