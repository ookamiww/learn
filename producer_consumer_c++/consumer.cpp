#include "consumer.h"

Consumer::Consumer()
{

}

Consumer::~Consumer()
{

}

void Consumer::run()
{

    while (true) {

        mutex.lock();

        if (queue.isEmpty()){
            qDebug() << "队列空,消费者进入休眠" << endl;
            condition.wait(&mutex);
        }

        int x = queue.dequeue();
        qDebug() << "消费者消费第" << x << "个数据:" << x << endl;

        condition.wakeAll();
        mutex.unlock();

        sleep(1);
    }
}
