#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pix = new QPixmap(QSize(341,221));
    pix->fill();
    painter = new QPainter(pix);                           //link pixmap to painter
    path = new QPainterPath;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setPixmap(*pix);                            //set pixmap to label

}

void MainWindow::paintEvent(QPaintEvent *)
{
    //use to clear screen and QPainterPath
    pix->fill();
    path = &QPainterPath();

    painter->setRenderHint(QPainter::Antialiasing, true);  //set painter type
    path->moveTo((qrand() % 80+1), (qrand() % 100+1));             //move to path start position

    path->cubicTo(200, 80, 320, 80, 341, 221);             //choose path type and path waypoints
    painter->setPen(QPen(Qt::black, qrand() % 8 +1));                   //set pen
    painter->drawPath(*path);                              //draw path on the painter
}

void MainWindow::setMouseValue(int x, int y)
{

    ui->textBrowser->append("("+QString::number(x)+","+QString::number(y)+")");

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->type()== QEvent::KeyPress)  //press any key
    {

         ui->label->setPixmap(*pix);
    }


}




//other QPainter drawing types

    //painter->save();  // 儲存繪圖裝置狀態

    //painter->setPen(QPen(Qt::blue, 4, DotLine));  // 藍色、4pixel大的點狀畫筆
    //painter->drawLine(x, y, x+w, y); // 由(x, y)繪到(x+w, y)

    //painter->setPen(SolidLine); // 實線
    //painter->setBrush(QBrush(Qt::green, DiagCrossPattern)); // �� 色的方� �畫刷
    //painter->drawRect(x, y, w, h); // 畫方塊，左上座標(x, y)，寬高(w, h)


    //painter->setBrush(Qt::yellow); // 實心黃色畫刷
    //painter->setBrush(NoBrush); // 無畫刷
    //p->drawRoundRect(x, y, w, h, 20, 20); // 圓角方塊，圓角半徑20pixel


    //painter->drawEllipse(x, y, w, h); // 以方塊為範圍的橢圓形
    //painter->drawPie(x, y, w, h, 45*16, 300*16); // 畫缺角的圓
    //painter->drawArc(x+3, y, w, h, 45*16, -60*16); // 畫弧
    //painter->drawChord(x, y, w, h, -45, 160*16); // 畫圓切


    //painter->drawPixmap(x, y, QPixmap("pengiun.xpm")); // 畫圖片

    //QBrush brush(Qt::lightGray);
    //qDrawWinButton(painter, x, y, w, h, colorGroup(), false, &brush);  // 畫一個按鈕

    // 填圖
    //painter->drawTiledPixmap(x+2, y+2, 2*w-16, 3*h-4, QPixmap("pengiun.xpm"));
    //painter->restore(); // 復原繪圖裝置狀態
