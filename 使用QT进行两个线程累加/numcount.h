#ifndef NUMCOUNT_H
#define NUMCOUNT_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

class NumCount : public QThread
{
public:
    NumCount();
    virtual ~NumCount();
protected:
    void run();
};

#endif // NUMCOUNT_H
