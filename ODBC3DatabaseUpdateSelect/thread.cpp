#include "thread.h"
#include <QMutex>

Thread::Thread(QObject *parent, bool state) :
    QThread(parent), stop(state)
{
}

void Thread::run()
{
    for (;;) {
        QMutex mutex;
        mutex.lock();
        if (this->stop)
            break;
        mutex.unlock();

        emit AtValueChanged();
        this->sleep(1);
    }
}
