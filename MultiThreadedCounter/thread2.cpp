#include "thread2.h"
#include <QMutex>

Thread2::Thread2(QObject *parent, bool state) :
    QThread(parent), stop(state)
{
}

void Thread2::run()
{
    for (;;) {
        QMutex mutex;
        mutex.lock();
        if(this->stop)
            break;
        mutex.unlock();

        emit AtValueChanged();
        this->msleep(500);
    }
}
