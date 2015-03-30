#ifndef THREADS_H
#define THREADS_H

#include <QThread>
#include <time.h>

class threads : public QThread
{
    Q_OBJECT
public:
    explicit threads();
    ~threads();
    void stop();
    
signals:
    void send_count_data(int count);
    
public slots:

protected:
    void run();

private:
    bool stopped;
    long int count;
    double NUM_SECONDS;
    
};

#endif // THREADS_H
