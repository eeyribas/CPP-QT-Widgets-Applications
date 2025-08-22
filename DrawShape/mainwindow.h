#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void DrawShape(QList<int> array, int x,
                   int array_lenght_int);

    QGraphicsScene *graphics_scene;
    QPixmap *pixmap;
    QPainter *painter;
    QPen pen;
    QList<int> left_color_values;
    QList<int> middle_color_values;
    QList<int> right_color_values;
    int array_length;
};

#endif // MAINWINDOW_H
