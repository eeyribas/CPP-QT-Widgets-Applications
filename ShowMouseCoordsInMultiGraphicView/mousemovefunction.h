#ifndef MOUSEMOVEFUNCTION_H
#define MOUSEMOVEFUNCTION_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QEvent>
#include <QRubberBand>

class MouseMoveFunction : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MouseMoveFunction(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

    bool left_right_button_state = false;
    int x_press_value, y_press_value;
    int x_first_move_value, y_first_move_value;
    int x_move_value, y_move_value;
    int x_last_move_value, y_last_move_value;

signals:
    void AtMousePressed();
    void AtMouseMoved();
    void AtMouseReleased();
    void AtMouseDoubleClick();
};

#endif // MOUSEMOVEFUNCTION_H
