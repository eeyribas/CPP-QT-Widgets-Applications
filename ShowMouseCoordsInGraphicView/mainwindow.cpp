#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_scene = new QGraphicsScene(this);
    pixmap = new QPixmap(167, 680);
    pixmap->fill(QColor(94, 94, 94));
    painter = new QPainter(pixmap);

    QList<int> array_1;
    QList<int> array_2;
    QList<int> array_3;
    int random_number = 0;
    for (int i = 0; i < 21; i++) {
        random_number = rand() % 5 + 1;
        array_1.append(random_number);
        random_number = rand() % 5 + 1;
        array_2.append(random_number);
        random_number = rand() % 5 + 1;
        array_3.append(random_number);
    }

    DrawShape(array_1, 0, 53, 34, 21);
    DrawShape(array_2, 57, 53, 34, 21);
    DrawShape(array_3, 114, 53, 34, 21);

    connect(ui->graphicsView, SIGNAL(AtMousePosition(QPoint&)),
            this, SLOT(OnShowMousePosition(QPoint&)));
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

void MainWindow::OnShowMousePosition(QPoint& pos)
{
    ui->label->setText(QString::number(pos.x()));
    ui->label_2->setText(QString::number(pos.y()));
}


void MainWindow::DrawShape(QList<int> array, int x, int width, int height, int array_lenght_int)
{
    for (int i = 0; i < array_lenght_int; i++) {
        if (array[i] == 0) {
            pen.setColor(QColor(94, 94, 94));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(118, 118, 118)));
            painter->drawRect(QRect(x, i * height, width, height));
        } else if(array[i] == 1) {
            pen.setColor(QColor(118, 118, 118));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(118, 118, 118)));
            painter->drawRect(QRect(x, i * height, width, height));
        } else if(array[i] == 2) {
            pen.setColor(QColor(194, 194, 194));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(194, 194, 194)));
            painter->drawRect(QRect(x, i * height, width, height));
        } else if(array[i] == 3) {
            pen.setColor(QColor(52, 154, 211));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(52, 152, 211)));
            painter->drawRect(QRect(x, i * height, width, height));
        } else if(array[i] == 4) {
            pen.setColor(QColor(150, 117, 0));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(150, 117, 0)));
            painter->drawRect(QRect(x, i * height, width, height));
        } else if(array[i] == 5) {
            pen.setColor(QColor(181, 0, 0));
            pen.setWidth(1);
            painter->setPen(pen);
            painter->setBrush(QBrush(QColor(181, 0, 0)));
            painter->drawRect(QRect(x, i * height, width, height));
        }
    }

    graphics_scene->addPixmap(*pixmap);
    ui->graphicsView->setScene(graphics_scene);
}
