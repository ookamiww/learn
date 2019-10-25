#ifndef BUFFER_H
#define BUFFER_H
#include <QMutex>
#include <QQueue>
#include <QDebug>
#include <QWaitCondition>

extern QMutex mutex;
extern QQueue<int> queue;
extern int i;
extern int MAX_SIZE;
extern QWaitCondition condition;

#endif // BUFFER_H
