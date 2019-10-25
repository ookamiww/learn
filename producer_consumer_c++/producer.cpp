#include "producer.h"

Producer::Producer()
{

}

Producer::~Producer()
{

}

void Producer::run()
{

    while (true) {

        mutex.lock();

        if (queue.size() == MAX_SIZE){
            qDebug() << "队列满,生产者进入休眠" << endl;
            condition.wait(&mutex);
        }

        i++;
        queue.enqueue(i);
        qDebug() << "生产者生产第" << i << "个数据:" << i << endl;

        condition.wakeAll();
        mutex.unlock();

        sleep(1);
    }
}
