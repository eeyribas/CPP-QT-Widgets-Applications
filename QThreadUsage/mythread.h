#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0, bool state = false);
    void run();
    bool stop;

signals:
    void AtValueChanged(int);
};

#endif // MYTHREAD_H
