#include "consumer.h"

Consumer::Consumer(QQueue<int> &queue,QMutex &mutex,QWaitCondition &condition)
{
    this->queue = &queue;
    this->mutex = &mutex;
    this->condition = &condition;

}

Consumer::~Consumer()
{

}

//void Consumer::setQueue(QQueue<int> &queue)
//{
//    this->queue = &queue;
//}

//void Consumer::setMutex(QMutex &mutex)
//{
//    this->mutex = &mutex;
//}

//void Consumer::setWaitCondition(QWaitCondition &condition)
//{
//    this->condition = &condition;
//}

void Consumer::run()
{
    while (true) {

        //锁开启
        mutex->lock();
        if(queue->isEmpty())
        {
            qDebug() << "队列空,消费者休眠" << endl;
            //休眠
            condition->wait(mutex);
        }

        int x = queue->dequeue();
        qDebug() << "消费者消费了第" << x << "个数据:" << x << endl;
        //唤醒所有线程
        condition->wakeAll();
        //解锁
        mutex->unlock();

        sleep(1);
    }

}
