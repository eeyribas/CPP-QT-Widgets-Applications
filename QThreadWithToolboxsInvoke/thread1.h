#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>

class Thread1 : public QThread
{
    Q_OBJECT
public:
    explicit Thread1(QObject *parent = 0, bool state = false);
    void run();

    bool stop;

signals:
    void AtValueChanged();
};

#endif // THREAD1_H
