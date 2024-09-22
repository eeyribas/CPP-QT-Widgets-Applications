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

    emit atStop1();
    emit atStop2();
}

void MainWindow::on_pushButton_clicked()
{
    job_1 = new Job();
    connect(job_1, &Job::atNumber,
            this, &MainWindow::NewNumber1);
    connect(this, &MainWindow::atStop1,
            job_1, &Job::Stop);

    QFuture<void> test = QtConcurrent::run(this->job_1, &Job::Start, QString("Test1"));
}

void MainWindow::on_pushButton_2_clicked()
{
    emit atStop1();
}

void MainWindow::on_pushButton_3_clicked()
{
    job_2 = new Job();
    connect(job_2, &Job::atNumber,
            this, &MainWindow::NewNumber2);
    connect(this, &MainWindow::atStop2,
            job_2, &Job::Stop);

    QFuture<void> test = QtConcurrent::run(this->job_2, &Job::Start, QString("Test2"));
}

void MainWindow::on_pushButton_4_clicked()
{
    emit atStop2();
}

void MainWindow::NewNumber1(QString name, int number)
{
    ui->lineEdit->setText(name + " " + QString::number(number));
}

void MainWindow::NewNumber2(QString name, int number)
{
    ui->lineEdit_2->setText(name + " " + QString::number(number));
}
