#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    released_state = false;
    moving_state = true;

    QGraphicsScene *graphics_scene = new QGraphicsScene(this);
    QPixmap *pixmap = new QPixmap(167, 680);
    pixmap->fill(QColor(94, 94, 94));
    QPainter *painter = new QPainter(pixmap);
    QPen pen;
    int random_number = 0;

    for (int i = 0; i < 21; i++) {
        random_number = rand() % 5 + 1;
        array_1.append(random_number);
        random_number = rand() % 5 + 1;
        array_2.append(random_number);
        random_number = rand() % 5 + 1;
        array_3.append(random_number);
    }
    DrawShape(ui->graphicsView, graphics_scene, pixmap, painter, pen, array_1, 0, 53, 34, 21);
    DrawShape(ui->graphicsView, graphics_scene, pixmap, painter, pen, array_2, 57, 53, 34, 21);
    DrawShape(ui->graphicsView, graphics_scene, pixmap, painter, pen, array_3, 114, 53, 34, 21);

    for (int i = 0; i < 21; i++) {
        random_number = rand() % 5 + 1;
        array_1.append(random_number);
        random_number = rand() % 5 + 1;
        array_2.append(random_number);
        random_number = rand() % 5 + 1;
        array_3.append(random_number);
    }
    DrawShape(ui->graphicsView_2, graphics_scene, pixmap, painter, pen, array_1, 0, 53, 34, 21);
    DrawShape(ui->graphicsView_2, graphics_scene, pixmap, painter, pen, array_2, 57, 53, 34, 21);
    DrawShape(ui->graphicsView_2, graphics_scene, pixmap, painter, pen, array_3, 114, 53, 34, 21);

    for (int i = 0; i < 21; i++) {
        random_number = rand() % 5 + 1;
        array_1.append(random_number);
        random_number = rand() % 5 + 1;
        array_2.append(random_number);
        random_number = rand() % 5 + 1;
        array_3.append(random_number);
    }
    DrawShape(ui->graphicsView_3, graphics_scene, pixmap, painter, pen, array_1, 0, 53, 34, 21);
    DrawShape(ui->graphicsView_3, graphics_scene, pixmap, painter, pen, array_2, 57, 53, 34, 21);
    DrawShape(ui->graphicsView_3, graphics_scene, pixmap, painter, pen, array_3, 114, 53, 34, 21);

    connect(ui->graphicsView, SIGNAL(atMousePressed()),
            this, SLOT(LeftMousePressedFunction()));
    connect(ui->graphicsView, SIGNAL(atMouseMoved()),
            this, SLOT(LeftMouseMovedFunction()));
    connect(ui->graphicsView, SIGNAL(atMouseReleased()),
            this, SLOT(LeftMouseReleasedFunction()));
    connect(ui->graphicsView, SIGNAL(atMouseDoubleClick()),
            this, SLOT(LeftMouseDoubleClickFunction()));

    connect(ui->graphicsView_2, SIGNAL(atMousePressed()),
            this, SLOT(MiddleMousePressedFunction()));
    connect(ui->graphicsView_2, SIGNAL(atMouseMoved()),
            this, SLOT(MiddleMouseMovedFunction()));
    connect(ui->graphicsView_2, SIGNAL(atMouseReleased()),
            this, SLOT(MiddleMouseReleasedFunction()));
    connect(ui->graphicsView_2, SIGNAL(atMouseDoubleClick()),
            this, SLOT(MiddleMouseDoubleClickFunction()));

    connect(ui->graphicsView_3, SIGNAL(atMousePressed()),
            this, SLOT(RightMousePressedFunction()));
    connect(ui->graphicsView_3, SIGNAL(atMouseMoved()),
            this, SLOT(RightMouseMovedFunction()));
    connect(ui->graphicsView_3, SIGNAL(atMouseReleased()),
            this, SLOT(RightMouseReleasedFunction()));
    connect(ui->graphicsView_3, SIGNAL(atMouseDoubleClick()),
            this, SLOT(RightMouseDoubleClickFunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LeftMousePressedFunction()
{
    MousePressedFunction(ui->label_8, ui->graphicsView->x_press_value, ui->graphicsView->y_press_value, 0);
}

void MainWindow::MiddleMousePressedFunction()
{
    MousePressedFunction(ui->label_11, ui->graphicsView_2->x_press_value, ui->graphicsView_2->y_press_value, 190);
}

void MainWindow::RightMousePressedFunction()
{
    MousePressedFunction(ui->label_12, ui->graphicsView_3->x_press_value, ui->graphicsView_3->y_press_value, 390);
}

void MainWindow::MousePressedFunction(QLabel *label, int tmp_x_press_value, int tmp_y_press_value, int x_sum)
{
    ui->label->setText("Mouse Pressed");
    ui->label_2->setText("x Pressed : " + QString::number(tmp_x_press_value));
    ui->label_3->setText("y Pressed : " + QString::number(tmp_y_press_value));
    released_state = false;
    moving_state = true;

    int y_coordinaat = tmp_y_press_value;
    if (y_coordinaat <= 15)
        y_coordinaat = 10;
    else if (y_coordinaat >= 685)
        y_coordinaat = 680;
    else
        y_coordinaat += 5;

    if (tmp_x_press_value > 11 && tmp_x_press_value < 65)
        label->setGeometry(11 + x_sum, y_coordinaat, 54, 10);
    else if (tmp_x_press_value > 68 && tmp_x_press_value < 122)
        label->setGeometry(68 + x_sum, y_coordinaat, 54, 10);
    else if (tmp_x_press_value > 125 && tmp_x_press_value < 179)
        label->setGeometry(125 + x_sum, y_coordinaat, 54, 10);
}

void MainWindow::LeftMouseMovedFunction()
{
    MouseMovedFunction(ui->label_8, ui->graphicsView->x_first_move_value, ui->graphicsView->y_first_move_value, ui->graphicsView->y_move_value, 0);
}

void MainWindow::MiddleMouseMovedFunction()
{
    MouseMovedFunction(ui->label_11, ui->graphicsView_2->x_first_move_value, ui->graphicsView_2->y_first_move_value, ui->graphicsView_2->y_move_value, 190);
}

void MainWindow::RightMouseMovedFunction()
{
   MouseMovedFunction(ui->label_12, ui->graphicsView_3->x_first_move_value, ui->graphicsView_3->y_first_move_value, ui->graphicsView_3->y_move_value, 390);
}

void MainWindow::MouseMovedFunction(QLabel *label, int tmp_x_first_move_value, int tmp_y_first_move_value, int tmp_y_move_value, int x_sum)
{
    if (moving_state == true) {
        ui->label->setText("Mouse Moving");
        ui->label_4->setText("x First Move: " + QString::number(tmp_x_first_move_value));
        ui->label_5->setText("y First Move: " + QString::number(tmp_y_first_move_value));
        released_state = true;
        int y_coordinaat = tmp_y_first_move_value;
        int y_move_coordinaat = tmp_y_move_value;

        if (y_coordinaat >= 10 && y_coordinaat <= 690 && y_move_coordinaat >= 10 && y_move_coordinaat <= 690) {

            int difference = y_move_coordinaat - y_coordinaat;
            if (difference < 0)
                y_coordinaat = y_coordinaat + difference;

            int height_geometry = abs(difference);
            if (tmp_x_first_move_value > 11 && tmp_x_first_move_value < 65)
                label->setGeometry(11 + x_sum, y_coordinaat, 54, height_geometry);
            else if (tmp_x_first_move_value > 68 && tmp_x_first_move_value < 121)
                label->setGeometry(68 + x_sum, y_coordinaat, 54, height_geometry);
            else if (tmp_x_first_move_value > 125 && tmp_x_first_move_value < 178)
                label->setGeometry(125 + x_sum, y_coordinaat, 54, height_geometry);
        }
    } else if(moving_state == false) {
        ui->label->setText("-------");
    }
}

void MainWindow::LeftMouseReleasedFunction()
{
    MouseReleasedFunction(ui->graphicsView, ui->label_8, ui->graphicsView->y_first_move_value, ui->graphicsView->x_last_move_value, ui->graphicsView->y_last_move_value);
}

void MainWindow::MiddleMouseReleasedFunction()
{
    MouseReleasedFunction(ui->graphicsView_2, ui->label_11, ui->graphicsView_2->y_first_move_value, ui->graphicsView_2->x_last_move_value, ui->graphicsView_2->y_last_move_value);
}

void MainWindow::RightMouseReleasedFunction()
{
    MouseReleasedFunction(ui->graphicsView_3, ui->label_12, ui->graphicsView_3->y_first_move_value, ui->graphicsView_3->x_last_move_value, ui->graphicsView_3->y_last_move_value);
}

void MainWindow::MouseReleasedFunction(QGraphicsView *graphics_view, QLabel *label, int tmp_y_first_move_value, int tmp_x_last_move_value, int tmp_y_last_move_value)
{
    if (released_state == true && moving_state == true) {
        ui->label_6->setText("x Last Move: " + QString::number(tmp_x_last_move_value));
        ui->label_7->setText("y Last Move: " + QString::number(tmp_y_last_move_value));
        moving_state = false;

        double difference_low = ((tmp_y_first_move_value) - 10) / 34;
        int difference_low_value = (int)(round(difference_low));
        double difference_high = ((tmp_y_last_move_value) - 10) / 34;
        int difference_high_value = (int)(round(difference_high));
        QList<int> tmp_array_1;
        QList<int> tmp_array_2;
        QList<int> tmp_array_3;
        int low_value = 0;
        int high_value = 0;

        if (difference_low_value < difference_high_value) {
            low_value = difference_low_value;
            high_value = difference_high_value;
        } else if(difference_low_value > difference_high_value) {
            low_value = difference_high_value;
            high_value = difference_low_value;
        }

        for (int i = low_value; i < high_value; i++) {
            tmp_array_1.append(array_1[i]);
            tmp_array_2.append(array_2[i]);
            tmp_array_3.append(array_3[i]);
        }

        ui->label_9->setText(QString::number(low_value));
        ui->label_10->setText(QString::number(high_value));

        label->setGeometry(10, 10, 0, 0);
        QGraphicsScene *graphics_scene = new QGraphicsScene(this);
        QPixmap *pixmap = new QPixmap(167, 680);
        pixmap->fill(QColor(94, 94, 94));
        QPainter *painter = new QPainter(pixmap);
        QPen pen;

        DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, tmp_array_1, 0, 53, 680 / tmp_array_1.size(), tmp_array_1.size());
        DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, tmp_array_2, 57, 53, 680 / tmp_array_2.size(), tmp_array_2.size());
        DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, tmp_array_3, 114, 53, 680 / tmp_array_3.size(), tmp_array_3.size());
    } else if(released_state == false) {
        ui->label_6->setText("x Last Move");
        ui->label_7->setText("y Last Move");
        moving_state = true;
    }
}

void MainWindow::LeftMouseDoubleClickFunction()
{
    MouseDoubleClickFunction(ui->graphicsView, ui->label_8, 0);
}

void MainWindow::MiddleMouseDoubleClickFunction()
{
    MouseDoubleClickFunction(ui->graphicsView_2, ui->label_11, 190);
}

void MainWindow::RightMouseDoubleClickFunction()
{
    MouseDoubleClickFunction(ui->graphicsView_3, ui->label_12, 390);
}

void MainWindow::MouseDoubleClickFunction(QGraphicsView *graphics_view, QLabel *label, int x_sum)
{
    QGraphicsScene *graphics_scene = new QGraphicsScene(this);
    QPixmap *pixmap = new QPixmap(167, 680);
    pixmap->fill(QColor(94, 94, 94));
    QPainter *painter = new QPainter(pixmap);
    QPen pen;
    released_state = false;

    DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, array_1, 0, 53, 34, 21);
    DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, array_2, 57, 53, 34, 21);
    DrawShape(graphics_view, graphics_scene, pixmap, painter, pen, array_3, 114, 53, 34, 21);

    label->setGeometry(125 + x_sum, 351, 53, 10);
    ui->label->setText("Double Click");
}

void MainWindow::DrawShape(QGraphicsView *graphics_view, QGraphicsScene *graphics_scene, QPixmap *pixmap, QPainter *painter, QPen pen, QList<int> array, int x, int width, int height, int array_lenght_int)
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
    graphics_view->setScene(graphics_scene);
}
