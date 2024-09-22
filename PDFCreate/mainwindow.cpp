#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("test.pdf");

    QPainter painter;
    if (!painter.begin(&printer)) {
        qDebug() << "Error!";
        return;
    }

    ui->graphicsView->render(&painter);
    painter.end();
}
