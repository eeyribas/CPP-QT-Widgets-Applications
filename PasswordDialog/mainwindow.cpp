#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    dialog = new Dialog(this);
    dialog->show();

    connect(dialog, SIGNAL(atData(QString)),
            this, SLOT(DialogFunction(QString)));
}

void MainWindow::DialogFunction(QString text)
{
    ui->label->setText(text);
}
