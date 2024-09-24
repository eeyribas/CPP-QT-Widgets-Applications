#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    counter_1 = 0;
    counter_2 = 1000;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    thread_1 = new Thread1();
    thread_1->stop = false;
    counter_1 = 0;
    connect(thread_1, SIGNAL(AtValueChanged()),
            this, SLOT(OnValueChanged1()));
    thread_1->start();

    thread_2 = new Thread2();
    thread_2->stop = false;
    counter_2 = 1000;
    connect(thread_2, SIGNAL(AtValueChanged()),
            this, SLOT(OnValueChanged2()));
    thread_2->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    thread_1->stop = true;
}

void MainWindow::on_pushButton_3_clicked()
{
    thread_2->stop = true;
}

void MainWindow::OnValueChanged1()
{
    counter_1++;
    QMetaObject::invokeMethod(ui->label, "setText", Q_ARG(QString, QString::number(counter_1)));
}

void MainWindow::OnValueChanged2()
{
    counter_2++;
    QMetaObject::invokeMethod(ui->label, "setText", Q_ARG(QString, QString::number(counter_2)));
}
