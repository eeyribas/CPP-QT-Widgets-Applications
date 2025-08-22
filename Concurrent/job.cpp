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

void Job::OnStart(QString name)
{
    stop = false;

    for (;;) {
        count++;

        if (stop)
            break;

        emit AtNumber(name, count);
        QThread::currentThread()->msleep(100);
    }
}

void Job::OnStop()
{
    stop = true;
    count = 0;
}
