#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_addIcon_clicked()
{
    for(int i=0;i<100;i++){
        int x=rand()%10;
        int y=rand()%10;
        if(ui->tableWidget->item(x,y)){}
        else
        {
            ui->tableWidget->setItem(x,y,new QTableWidgetItem(QIcon(":/icon/icons/life.ico"),""));
            break;
        }
    }
}

void MainWindow::on_pushButton_reset_clicked()
{
    ui->tableWidget->clear();
}

void MainWindow::on_actionToolBarAdd_triggered()
{
    on_pushButton_addIcon_clicked();
}

void MainWindow::on_actionToolBarReset_triggered()
{
    on_pushButton_reset_clicked();
}
