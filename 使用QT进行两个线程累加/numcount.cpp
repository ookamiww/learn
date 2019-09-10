#include "numcount.h"

static int num = 0;
static QMutex mutex;
static QWaitCondition condition;

NumCount::NumCount()
{

}

NumCount::~NumCount()
{

}

void NumCount::run()
{
    while (true) {
        mutex.lock();
        condition.wakeAll();
        qDebug() << "数字为: " << num;
        ++num;
        qDebug() << "线程ID:" << QThread::currentThreadId() << "+1后输出数字:" << num << endl;
        sleep(1);
        if(isRunning())
            condition.wait(&mutex);
        mutex.unlock();
    }

}
