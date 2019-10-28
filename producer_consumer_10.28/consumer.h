#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QThread>
#include <QQueue>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>

class Consumer : public QThread
{
public:
    Consumer(QQueue<int> &queue,QMutex &mutex,QWaitCondition &condition);
    ~Consumer();
//    void setQueue(QQueue<int> &queue);
//    void setMutex(QMutex &mutex);
//    void setWaitCondition(QWaitCondition &condition);
    void run();

private:
    QQueue<int> *queue;
    QMutex *mutex;
    QWaitCondition *condition;

};

#endif // CONSUMER_H
