#include <QCoreApplication>
#include <consumer.h>
#include <producer.h>
#include <QQueue>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMutex mutex;
    QWaitCondition condition;
    QQueue<int> queue;


    Producer p(queue,mutex,condition);
    Consumer c(queue,mutex,condition);

//    p.setQueue(queue);
//    p.setMutex(mutex);
//    p.setWaitCondition(condition);

//    c.setQueue(queue);
//    c.setMutex(mutex);
//    c.setWaitCondition(condition);

    p.start();
    c.start();

    return a.exec();
}
