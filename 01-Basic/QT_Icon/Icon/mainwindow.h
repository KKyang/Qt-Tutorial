#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_addIcon_clicked();

    void on_pushButton_reset_clicked();

    void on_actionToolBarReset_triggered();

    void on_actionToolBarAdd_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
