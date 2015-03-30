#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "threads.h"

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
    void get_count_data(int count);
    void on_thread_start_button_clicked();

    void on_thread_stop_button_clicked();

    void on_thread_reset_button_clicked();

private:
    Ui::MainWindow *ui;
    threads *multi;
};

#endif // MAINWINDOW_H
