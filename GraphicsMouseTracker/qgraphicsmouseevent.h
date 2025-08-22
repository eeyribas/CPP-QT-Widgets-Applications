#ifndef QGRAPHICSMOUSEEVENT_H
#define QGRAPHICSMOUSEEVENT_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class QGraphicsMouseEvent : public QGraphicsView
{
    Q_OBJECT

public:
    QGraphicsMouseEvent(QWidget *parent = 0);
    ~QGraphicsMouseEvent();

signals:
    void AtMousePosition(QPoint &point);

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
};

#endif // QGRAPHICSMOUSEEVENT_H
