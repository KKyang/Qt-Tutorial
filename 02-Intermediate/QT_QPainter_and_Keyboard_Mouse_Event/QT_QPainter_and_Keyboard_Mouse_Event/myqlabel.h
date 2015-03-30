#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QString>
class MyQlabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyQlabel(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void sendXY(int x,int y);
    void sendString(const QString& xy);

public slots:

};

#endif // MYQLABEL_H
