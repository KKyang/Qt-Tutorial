#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void receive_timer_count();

    void on_pushButton_start_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_doubleSpinBox_timer_interval_setup_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    QTimer *Interval;

    double timerInterval;

    long int timerCount;
};

#endif // MAINWINDOW_H
