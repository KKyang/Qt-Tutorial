#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adj =0;
}

MainWindow::~MainWindow()
{
    disconnectLightness();
    delete ui;
}

void MainWindow::on_actionLoad_BMP_Files_triggered()
{
    //get file path
    fileName = QFileDialog::getOpenFileName(this, "Open Image", QDir::currentPath(), "BMP files (*.bmp)").toStdString();
    if(!fileName.empty())
    {
        //read BMP file
        image.read(fileName.c_str());

        //import to QImage
        refreshImage();

        //set button enable
        ui->actionSave_BMP_Image_Using_fstream->setEnabled(true);
        ui->actionSave_BMP_Image_Using_QImage->setEnabled(true);
        ui->actionRedo->setEnabled(false);
        ui->actionUndo->setEnabled(false);
        ui->actionAdjust_64->setEnabled(false);
        disconnectLightness();
    }
}

void MainWindow::on_actionLoad_64_Files_triggered()
{
    //get file path
    fileName = QFileDialog::getOpenFileName(this, "Open Image", QDir::currentPath(), "64 files (*.64)").toStdString();
    if(!fileName.empty())
    {
        //read BMP file
        image.read(fileName.c_str());

        //import to QImage
        refreshImage();

        //set button enable
        ui->actionSave_BMP_Image_Using_fstream->setEnabled(true);
        ui->actionSave_BMP_Image_Using_QImage->setEnabled(true);
        ui->actionRedo->setEnabled(false);
        ui->actionUndo->setEnabled(false);
        ui->actionAdjust_64->setEnabled(true);
    }
}

void MainWindow::on_actionSave_BMP_Image_Using_QImage_triggered()
{
    QString name = saveImage();
    if(!name.isEmpty())
    {
        test.save(name);
    }
}

void MainWindow::on_actionSave_BMP_Image_Using_fstream_triggered()
{
    QString name = saveImage();
    if(!name.isEmpty())
    {
      image.write(name.toStdString().c_str());
    }
}

void MainWindow::on_actionResize_triggered()
{
    if(!image.isEmpty() && image.getWidth() >= 50 && image.getHeight() >=50)
    {
        DialogImageResize propertiesDialog;
        propertiesDialog.setValue(image.getWidth(), image.getHeight());

        if(propertiesDialog.exec() == QDialog::Accepted)
        {
            undo.copyFrom(&image);
            image.resize(propertiesDialog.getWidthPixel(), propertiesDialog.getHeightPixel(), propertiesDialog.isKeepAspectRatio());
            test = QImage(image.getData(),image.getWidth(),image.getHeight(),image.getStep(),QImage::Format_RGB888);
            refreshImage();
            ui->actionUndo->setEnabled(true);
            ui->actionRedo->setEnabled(false);
        }
    }
    else
    {
        QMessageBox::warning(this, "Something happens!", "No image is loaded or the image is too small.\n(Images smaller than 50 pixels aren't able to load.)");
    }
}


void MainWindow::on_actionHistogram_triggered()
{
    if(!image.isEmpty())
    {
        myCV::myMat* r, * g,*  b;
        r = new myCV::myMat();
        g = new myCV::myMat();
        b = new myCV::myMat();
        std::vector<std::vector<int>> statistic;
        statistic.resize(3);
        r->copyFrom(image.getHistogram(myCV::myMat::Histogram::R,statistic[0]).get(), 256, 100, 3 * 256);
        g->copyFrom(image.getHistogram(myCV::myMat::Histogram::G,statistic[1]).get(), 256, 100, 3 * 256);
        b->copyFrom(image.getHistogram(myCV::myMat::Histogram::B,statistic[2]).get(), 256, 100, 3 * 256);
        DialogHistogram histogram;
        size_t fileHead = fileName.find_last_of("/") + 1;
        size_t fileNameLength = fileName.find_last_of(".") - fileHead;

        //Get current path & file name
        histogram.setName(fileName.substr(fileHead, fileNameLength));
        histogram.setHistogram(r,g,b);
        histogram.setStatisticResult(statistic);
        delete r,g,b;
        histogram.exec();
    }
    else
    {
        QMessageBox::warning(this, "Something happens!", "No image is loaded!");
    }
}

void MainWindow::on_actionGrayscale_triggered()
{
    if(!image.isEmpty())
    {
        undo.copyFrom(&image);
        image.convertFormat(myCV::myMat::Transform::RGB2GRAY);

        refreshImage();
        ui->actionUndo->setEnabled(true);
        ui->actionRedo->setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Something happens!", "No image is loaded!");
    }
}

void MainWindow::on_actionUndo_triggered()
{
    redo.copyFrom(&image);
    image.copyFrom(&undo);
    refreshImage();
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(true);
}

void MainWindow::on_actionRedo_triggered()
{
    undo.copyFrom(&image);
    image.copyFrom(&redo);
    refreshImage();
    ui->actionUndo->setEnabled(true);
    ui->actionRedo->setEnabled(false);
}

void MainWindow::on_actionBlur_triggered()
{
    if(!image.isEmpty())
    {
        DialogBlur blurProperties;

        if(blurProperties.exec() == QDialog::Accepted)
        {
            undo.copyFrom(&image);
            if(blurProperties.useGaussian())
                myCV::myBlur::gaussianBlur(&image, &image, blurProperties.getMaskSize(), blurProperties.getSigma());
            else
                myCV::myBlur::simpleBlur(&image, &image, blurProperties.getMaskSize());
            refreshImage();
            ui->actionUndo->setEnabled(true);
            ui->actionRedo->setEnabled(false);
        }
    }
}


QString MainWindow::saveImage()
{
    //Extract file name from string
    size_t fileHead = fileName.find_last_of("/") + 1;
    size_t fileNameLength = fileName.find_last_of(".") - fileHead;

    //Get current path & file name
    QString saveFileName = QDir::currentPath() + "/" + QString::fromStdString(fileName.substr(fileHead, fileNameLength)) + "-modified" + ".bmp";

    //rename flag
    int count = 2;
    while(1)
    {
        //check if there's any duplicated file name.
        if(QFile::exists(saveFileName))
        {
            saveFileName = QDir::currentPath() + "/" + QString::fromStdString(fileName.substr(fileHead, fileNameLength)) + "-modified-" + QString::number(count) + ".bmp";
            count++;
        }
        else
        {
            break;
        }
    }

    //open file dialog
    saveFileName = QFileDialog::getSaveFileName(this, "Save Image", saveFileName, "BMP files (*.bmp)");

    return saveFileName;
}

void MainWindow::refreshImage()
{
    test = QImage(image.getData(),image.getWidth(),image.getHeight(),image.getStep(),QImage::Format_RGB888);
    QImage showImage;
    showImage = test;
    if(image.getWidth() > 2000)
    {
        showImage = test.scaled(image.getWidth()/2, image.getHeight()/2);
    }
    else if(image.getWidth() < 100)
    {
        showImage = test.scaled(image.getWidth()*4, image.getHeight()*4);
    }
    else
    {
        showImage = test;
    }

    QRect mainWindowGeometry = this->geometry();
    mainWindowGeometry.setWidth(showImage.width());
    mainWindowGeometry.setHeight(showImage.height()+54);
    this->setGeometry(mainWindowGeometry);
    ui->show_BMP_files->setGeometry(0,0,showImage.width(), showImage.height());
    ui->show_BMP_files->setPixmap(QPixmap::fromImage(showImage));
}

void MainWindow::on_actionAdjust_64_triggered()
{
    if(adj == 0)
    {
        adj = new DialogAdjust64();
        connect(adj,SIGNAL(sendLightness(int)),this,SLOT(receiveLightness(int)));
    }
    adj->exec();

}

void MainWindow::receiveLightness(int ness)
{
    locker.lock();
    if(!image.isEmpty())
    {
        image.adjust64(ness);
        refreshImage();
        ui->actionUndo->setEnabled(true);
        ui->actionRedo->setEnabled(false);
    }
    locker.unlock();

}


void MainWindow::disconnectLightness()
{
    if(adj)
    {
        disconnect(adj,SIGNAL(sendLightness(int)),this,SLOT(receiveLightness(int)));
        delete adj;
    }
}
