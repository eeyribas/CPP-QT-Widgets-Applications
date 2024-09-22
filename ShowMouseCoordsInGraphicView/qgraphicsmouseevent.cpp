#include "qgraphicsmouseevent.h"

QGraphicsMouseEvent::QGraphicsMouseEvent(QWidget* parent) : QGraphicsView (parent)
{
    this->setMouseTracking(true);
}

QGraphicsMouseEvent::~QGraphicsMouseEvent()
{

}

void QGraphicsMouseEvent::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();
    if (mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()) {
        if (mouse_pos.x() > 0 && mouse_pos.y() > 0)
            emit atMousePosition(mouse_pos);
    }
}
