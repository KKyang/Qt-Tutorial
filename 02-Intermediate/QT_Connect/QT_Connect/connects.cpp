#include "connects.h"

connects::connects(QObject *parent) :
    QObject(parent)
{
    count = 0;
}


void connects::get_signal(bool sig)
{
    if(sig)
    {
        count++;
    }
    else
    {
        count = 0;
    }
        send_number(count);
}

