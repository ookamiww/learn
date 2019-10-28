#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QThread>
#include <QQueue>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>

class Producer : public QThread
{
public:
    Producer(QQueue<int> &queue,QMutex &mutex,QWaitCondition &condition);
    ~Producer();
//    void setQueue(QQueue<int> queue);
//    void setMutex(QMutex &mutex);
//    void setWaitCondition(QWaitCondition &condition);
    void run();

private:
    int count = 1;
    int MAX_SIZE = 5;
    QQueue<int> *queue;
    QMutex *mutex;
    QWaitCondition *condition;

};

#endif // PRODUCER_H
