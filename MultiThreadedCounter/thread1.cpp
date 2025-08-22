#include "thread1.h"
#include <QMutex>

Thread1::Thread1(QObject *parent, bool state) :
    QThread(parent), stop(state)
{
}

void Thread1::run()
{
    for (;;) {
        QMutex mutex;
        mutex.lock();
        if (this->stop)
            break;
        mutex.unlock();

        emit AtValueChanged();
        this->msleep(500);
    }
}
