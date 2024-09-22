#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MakePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlot()
{
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; i++) {
        x[i] = i / 50.0 - 1;
        y[i] = x[i] * x[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();
}
