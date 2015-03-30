#ifndef DIALOGIMAGERESIZE_H
#define DIALOGIMAGERESIZE_H

#include <QDialog>

namespace Ui {
class DialogImageResize;
}

class DialogImageResize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogImageResize(QWidget *parent = 0);
    ~DialogImageResize();

    void setValue(int x, int y);
    int getWidthPixel() const;
    int getHeightPixel() const;
    bool isKeepAspectRatio() const;

private:
    Ui::DialogImageResize *ui;
};

#endif // DIALOGIMAGERESIZE_H
