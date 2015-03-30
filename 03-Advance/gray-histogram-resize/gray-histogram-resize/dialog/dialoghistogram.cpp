#include "dialoghistogram.h"
#include "ui_dialoghistogram.h"

DialogHistogram::DialogHistogram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistogram)
{
    ui->setupUi(this);
    R = new myCV::myMat();
    G = new myCV::myMat();
    B = new myCV::myMat();
}

DialogHistogram::~DialogHistogram()
{
    delete R, G, B;
    delete ui;
}

void DialogHistogram::setHistogram(const myCV::myMat* _srcR, const myCV::myMat* _srcG, const myCV::myMat* _srcB)
{
    R->copyFrom(_srcR);
    G->copyFrom(_srcG);
    B->copyFrom(_srcB);
    QImage QR(R->getData(),R->getWidth(), R->getHeight(), R->getStep(),QImage::Format_RGB888);
    QImage QG(G->getData(),G->getWidth(), G->getHeight(), G->getStep(),QImage::Format_RGB888);
    QImage QB(B->getData(),B->getWidth(), B->getHeight(), B->getStep(),QImage::Format_RGB888);
    ui->labelHistogramR->setPixmap(QPixmap::fromImage(QR));
    ui->labelHistogramG->setPixmap(QPixmap::fromImage(QG));
    ui->labelHistogramB->setPixmap(QPixmap::fromImage(QB));
}

void DialogHistogram::setStatisticResult(std::vector<std::vector<int>> _statistic)
{
    statisticResult.resize(_statistic.size());
    for(int i=0;i<_statistic.size();i++)
    {
        statisticResult[i].resize(_statistic[i].size());
        for(int j=0;j<_statistic[i].size();j++)
        {
            statisticResult[i][j]=_statistic[i][j];
        }
    }
}

void DialogHistogram::on_pushButton_saveHistogram_clicked()
{
    R->write("histogramR.bmp");
    G->write("histogramG.bmp");
    B->write("histogramB.bmp");
}

void DialogHistogram::on_pushButton_saveText_clicked()
{
    std::fstream outFile;
    std::string fileName = QFileDialog::getSaveFileName(this, "Open Image", QDir::currentPath(), "text files (*.txt)").toStdString();
    outFile.open(fileName, std::ios::out);
    if(!outFile.is_open())
    {
        QMessageBox::warning(this, "Something happens!", "Text cannot open!");
        return;
    }

    outFile << "Picture: " << pictureName << std::endl;
    outFile << "*Note: if an image is a gray image, you'll get three same R, G, B histograms!"<<std::endl;
    outFile << "==============================================================================="<<std::endl;
    for(int i=0; i< 3;i++)
    {
        if(i==0)outFile << "R Channel:"<<std::endl;
        else if(i==1)outFile << "B Channel:"<<std::endl;
        else if(i==2)outFile << "G Channel:"<<std::endl;
        for(int j=0;j<256;j++)
        {
            outFile << "Pixel [" << j << "] "<<statisticResult[i][j]<<std::endl;

        }
        outFile << "==============================================================================="<<std::endl;
    }
    outFile.close();
}
