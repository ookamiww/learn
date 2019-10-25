#ifndef CONSUMER_H
#define CONSUMER_H
#include <QThread>
#include <buffer.h>

class Consumer : public QThread
{
public:
    Consumer();
    ~Consumer();
    void run();
};

#endif // CONSUMER_H
