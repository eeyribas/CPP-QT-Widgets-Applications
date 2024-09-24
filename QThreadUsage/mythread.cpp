#include "mythread.h"
#include <QDebug>
#include <QMutex>

MyThread::MyThread(QObject *parent, bool state) : QThread(parent), stop(state)
{
}

void MyThread::run()
{
    for (int i = 0; i < 100; i++) {
        QMutex mutex;
        mutex.lock();
        if(this->stop)
            break;
        mutex.unlock();

        emit AtValueChanged(i);
        this->msleep(500);
    }
}
