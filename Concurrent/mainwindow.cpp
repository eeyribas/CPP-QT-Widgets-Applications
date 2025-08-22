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

    emit AtStop1();
    emit AtStop2();
}

void MainWindow::on_pushButton_clicked()
{
    job_1 = new Job();
    connect(job_1, &Job::AtNumber,
            this, &MainWindow::OnNewNumber1);
    connect(this, &MainWindow::AtStop1,
            job_1, &Job::OnStop);

    QFuture<void> test = QtConcurrent::run(this->job_1, &Job::OnStart,
                                           QString("Test1"));
}

void MainWindow::on_pushButton_2_clicked()
{
    emit AtStop1();
}

void MainWindow::on_pushButton_3_clicked()
{
    job_2 = new Job();
    connect(job_2, &Job::AtNumber,
            this, &MainWindow::OnNewNumber2);
    connect(this, &MainWindow::AtStop2,
            job_2, &Job::OnStop);

    QFuture<void> test = QtConcurrent::run(this->job_2, &Job::OnStart,
                                           QString("Test2"));
}

void MainWindow::on_pushButton_4_clicked()
{
    emit AtStop2();
}

void MainWindow::OnNewNumber1(QString name, int number)
{
    ui->lineEdit->setText(name + " " + QString::number(number));
}

void MainWindow::OnNewNumber2(QString name, int number)
{
    ui->lineEdit_2->setText(name + " " + QString::number(number));
}
