#include "myqlabel.h"

MyQlabel::MyQlabel(QWidget *parent) :
    QLabel(parent)
{
}

void MyQlabel::mousePressEvent(QMouseEvent *ev)
{
    emit sendXY(ev->x(),ev->y());

}

void MyQlabel::mouseMoveEvent(QMouseEvent *ev)
{

    QString text("("+QString::number(ev->x())+","+QString::number(ev->y())+")");
    emit sendString(text);
}

void MyQlabel::mouseReleaseEvent(QMouseEvent *ev)
{
}

