#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QThread>

class Job : public QObject
{
    Q_OBJECT
public:
    explicit Job(QObject *parent = nullptr);
    ~Job();

signals:
    void atNumber(QString name, int number);

public slots:
    void Start(QString name);
    void Stop();

private:
    bool stop;
    int count;
};

#endif // JOB_H
