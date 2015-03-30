#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connects.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void send_signal(bool sig);

    
private slots:
    void get_feedback_signal(int count);

    void on_pushButton_send_signal_1_clicked();

    void on_pushButton_send_signal_0_clicked();

private:
    Ui::MainWindow *ui;
    connects *connection;
};

#endif // MAINWINDOW_H
