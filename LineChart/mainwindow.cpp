#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    count = 0;

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(QColor(220,110,255)));
    ui->widget->yAxis->setRange(-2,2);

    connect(&data_timer, SIGNAL(timeout()),
            this, SLOT(RealTimeData()));
    data_timer.start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RealTimeData()
{
    static QTime time(QTime::currentTime());
    double key_time = time.elapsed() / 1000.0;

    double value = qSin(key_time);
    ui->widget->graph(0)->addData(key_time, value);
    ui->widget->xAxis->rescale();
    ui->widget->replot();
}
