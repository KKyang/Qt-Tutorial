#include "dialogimageresize.h"
#include "ui_dialogimageresize.h"

DialogImageResize::DialogImageResize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogImageResize)
{
    ui->setupUi(this);
}

DialogImageResize::~DialogImageResize()
{
    delete ui;
}

void DialogImageResize::setValue(int x ,int y)
{
    ui->spinBox_pixelX->setValue(x);
    ui->spinBox_pixelY->setValue(y);
}

int DialogImageResize::getWidthPixel() const
{
    return this->ui->spinBox_pixelX->value();
}

int DialogImageResize::getHeightPixel() const
{
    return this->ui->spinBox_pixelY->value();
}

bool DialogImageResize::isKeepAspectRatio() const
{
    return this->ui->checkBox_keepAspectRatio->isChecked();
}
