#ifndef CONNECTS_H
#define CONNECTS_H

#include <QObject>

class connects : public QObject
{
    Q_OBJECT
public:
    explicit connects(QObject *parent = 0);
    
signals:
    void send_number(const int count);

public slots:
    void get_signal(bool sig);

private:
    int count;
    
};

#endif // CONNECTS_H
