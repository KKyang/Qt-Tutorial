#ifndef DIALOGHISTOGRAM_H
#define DIALOGHISTOGRAM_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include "mymat.h"

namespace Ui {
class DialogHistogram;
}

class DialogHistogram : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistogram(QWidget *parent = 0);
    ~DialogHistogram();
    void setHistogram(const myCV::myMat* _srcR, const myCV::myMat* _srcG, const myCV::myMat* _srcB);
    void setName(const std::string n){pictureName = n;}
    void setStatisticResult(std::vector<std::vector<int>> _statistic);

private slots:
    void on_pushButton_saveHistogram_clicked();

    void on_pushButton_saveText_clicked();

private:
    Ui::DialogHistogram *ui;
    myCV::myMat* R, *G, *B;
    std::string pictureName;
    std::vector<std::vector<int>> statisticResult;

};

#endif // DIALOGHISTOGRAM_H
