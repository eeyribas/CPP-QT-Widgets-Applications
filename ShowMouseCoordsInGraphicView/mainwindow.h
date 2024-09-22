#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

public slots:
    void ShowMousePosition(QPoint &point);

private:
    Ui::MainWindow *ui;

    void DrawShape(QList<int> array, int x, int width, int height, int array_lenght_int);

    QGraphicsScene *graphics_scene;
    QPixmap *pixmap;
    QPainter *painter;
    QPen pen;
};

#endif // MAINWINDOW_H
