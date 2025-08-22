#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(unsigned(time(0)));
    double number = RandomFunction(1, 10);
    number = RoundFunction(number, 2);
    ui->label->setText(QString::number(number));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::RandomFunction(double min, double max)
{
    return min + (max - min) * ((double)rand() / (double)RAND_MAX);
}

double MainWindow::RoundFunction(double number, int pow_factor)
{
    double tmp_number = number * pow(10, pow_factor);
    tmp_number = round(tmp_number);
    tmp_number = tmp_number / pow(10, pow_factor);

    return tmp_number;
}
