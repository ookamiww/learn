#include "producer.h"

Producer::Producer(QQueue<int> &queue,QMutex &mutex,QWaitCondition &condition)
{
    this->queue = &queue;
    this->mutex = &mutex;
    this->condition = &condition;
}

Producer::~Producer()
{

}

//void Producer::setQueue(QQueue<int> &queue)
//{
//    this->queue = &queue;
//}

//void Producer::setMutex(QMutex &mutex)
//{
//    this->mutex = &mutex;
//}

//void Producer::setWaitCondition(QWaitCondition &condition)
//{
//    this->condition = &condition;
//}

void Producer::run()
{
    while (true) {

        //锁开启
        mutex->lock();
        if(queue->size() >= MAX_SIZE){
            qDebug() << "队列满,生产者休眠" << endl;
            //休眠
            condition->wait(mutex);
        }

        queue->enqueue(count);
        qDebug() << "生产者生产了第" << count << "个数据:" << count << endl;
        count++;
        //唤醒全部线程
        condition->wakeAll();
        //解锁
        mutex->unlock();

        sleep(1);

    }

}
