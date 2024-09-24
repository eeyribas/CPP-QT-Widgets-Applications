#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    my_thread = new MyThread(this);
    connect(my_thread, SIGNAL(AtValueChanged(int)),
            this, SLOT(OnValueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    my_thread->stop = false;
    my_thread->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    my_thread->stop = true;
}

void MainWindow::OnValueChanged(int value)
{
    ui->label->setText(QString::number(value));
}
