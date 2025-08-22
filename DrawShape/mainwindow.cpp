#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_scene = new QGraphicsScene(this);
    pixmap = new QPixmap(167, 680);
    pixmap->fill(QColor(94, 94, 94));
    painter = new QPainter(pixmap);
    array_length = 20;

    for (int i = 0; i < array_length; i++) {
        left_color_values.append(0);
        middle_color_values.append(0);
        right_color_values.append(0);
    }
    DrawShape(left_color_values, 0, array_length);
    DrawShape(middle_color_values, 57, array_length);
    DrawShape(right_color_values, 114, array_length);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (graphics_scene)
        delete graphics_scene;

    if (pixmap)
        delete pixmap;

    if (painter)
        delete painter;
}

void MainWindow::DrawShape(QList<int> array, int x, int array_length_int)
{
    pen.setColor(QColor(94, 94, 94));
    pen.setWidth(1);
    painter->setPen(pen);

    for (int i = 0; i < array_length_int; i++) {
        if (array[i] == 0) {
            painter->setBrush(QBrush(QColor(118, 118, 118)));
            painter->drawRect(QRect(x, i * 34, 53, 34));
        }
    }

    graphics_scene->addPixmap(*pixmap);
    ui->graphicsView->setScene(graphics_scene);
}
