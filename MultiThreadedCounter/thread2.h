#ifndef THREAD2_H
#define THREAD2_H

#include <QThread>

class Thread2 : public QThread
{
    Q_OBJECT
public:
    explicit Thread2(QObject *parent = 0, bool state = false);
    void run();

    bool stop;

signals:
    void AtValueChanged();
};

#endif // THREAD2_H
