#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <cstdlib>
#include <cmath>
#include <mousemovefunction.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void LeftMousePressedFunction();
    void MiddleMousePressedFunction();
    void RightMousePressedFunction();
    void MousePressedFunction(QLabel *label, int tmp_x_press_value, int tmp_y_press_value, int x_sum);
    void LeftMouseMovedFunction();
    void MiddleMouseMovedFunction();
    void RightMouseMovedFunction();
    void MouseMovedFunction(QLabel *label, int tmp_x_first_move_value, int tmp_y_first_move_value, int tmp_y_move_value, int x_sum);
    void LeftMouseReleasedFunction();
    void MiddleMouseReleasedFunction();
    void RightMouseReleasedFunction();
    void MouseReleasedFunction(QGraphicsView *graphics_view, QLabel *label, int tmp_y_first_move_value, int tmp_x_last_move_value, int tmp_y_last_move_value);
    void LeftMouseDoubleClickFunction();
    void MiddleMouseDoubleClickFunction();
    void RightMouseDoubleClickFunction();
    void MouseDoubleClickFunction(QGraphicsView *graphics_view, QLabel *label, int x_sum);

private:
    Ui::MainWindow *ui;

    void DrawShape(QGraphicsView *graphics_view, QGraphicsScene *graphics_scene, QPixmap *pixmap, QPainter *painter, QPen pen, QList<int> array,
                   int x, int width, int height, int array_lenght_int);

    QList<int> array_1;
    QList<int> array_2;
    QList<int> array_3;
    bool released_state;
    bool moving_state;
};

#endif // MAINWINDOW_H
