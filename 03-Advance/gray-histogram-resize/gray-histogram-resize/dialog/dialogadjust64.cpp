#include "dialogadjust64.h"
#include "ui_dialogadjust64.h"

DialogAdjust64::DialogAdjust64(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdjust64)
{
    ui->setupUi(this);
}

DialogAdjust64::~DialogAdjust64()
{
    delete ui;
}

void DialogAdjust64::on_horizontalSlider_lightness_sliderReleased()
{
   emit sendLightness(ui->horizontalSlider_lightness->value());
}
