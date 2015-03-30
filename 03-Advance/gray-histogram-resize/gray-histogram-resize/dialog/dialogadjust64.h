#ifndef DIALOGADJUST64_H
#define DIALOGADJUST64_H

#include <QDialog>

namespace Ui {
class DialogAdjust64;
}

class DialogAdjust64 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdjust64(QWidget *parent = 0);
    ~DialogAdjust64();

private slots:
    void on_horizontalSlider_lightness_sliderReleased();

signals:
    void sendLightness(int);

private:
    Ui::DialogAdjust64 *ui;
};

#endif // DIALOGADJUST64_H
