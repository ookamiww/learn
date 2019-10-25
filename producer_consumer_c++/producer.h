#ifndef PRODUCER_H
#define PRODUCER_H
#include <QThread>
#include <buffer.h>

class Producer : public QThread
{
public:
    Producer();
    ~Producer();
    void run();
};

#endif // PRODUCER_H
