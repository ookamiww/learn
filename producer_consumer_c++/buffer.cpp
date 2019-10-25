#include "buffer.h"

QMutex mutex;
QQueue<int> queue;
int i = 0;
int MAX_SIZE = 5;
QWaitCondition condition;
