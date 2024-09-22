#include "mousemovefunction.h"

MouseMoveFunction::MouseMoveFunction(QWidget *parent) : QGraphicsView (parent)
{

}

void MouseMoveFunction::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        this->x_press_value = e->x();
        this->y_press_value = e->y();

        left_right_button_state = false;
        emit atMousePressed();

    } else if (e->button() == Qt::RightButton) {
        this->x_first_move_value = e->x();
        this->y_first_move_value = e->y();

        left_right_button_state = true;
        emit atMouseMoved();
    }
}

void MouseMoveFunction::mouseMoveEvent(QMouseEvent *e)
{
    if (left_right_button_state == true) {
        this->x_move_value = e->x();
        this->y_move_value = e->y();

        emit atMouseMoved();
    }
}

void MouseMoveFunction::mouseReleaseEvent(QMouseEvent *e)
{
    if (left_right_button_state == true) {
        this->x_last_move_value = e->x();
        this->y_last_move_value = e->y();

        emit atMouseReleased();
    }
}

void MouseMoveFunction::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (left_right_button_state == true)
        emit atMouseDoubleClick();
}
