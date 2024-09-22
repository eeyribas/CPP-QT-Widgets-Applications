#include "job.h"

Job::Job(QObject *parent) : QObject(parent)
{
    stop = false;
    count = 0;
}

Job::~Job()
{
    stop = false;
}

void Job::Start(QString name)
{
    stop = false;

    for (;;) {
        count++;

        if (stop)
            break;
        emit atNumber(name, count);
        QThread::currentThread()->msleep(100);
    }
}

void Job::Stop()
{
    stop = true;
    count = 0;
}
