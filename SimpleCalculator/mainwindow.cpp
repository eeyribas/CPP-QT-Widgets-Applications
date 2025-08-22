#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(AtSum()),
            this, SLOT(OnSumFunction()));
    connect(this, SIGNAL(AtSubstract()),
            this, SLOT(OnSubstractFunction()));
    connect(this, SIGNAL(AtMultiple()),
            this, SLOT(OnMultipleFunction()));
    connect(this, SIGNAL(AtDivide()),
            this, SLOT(OnDivideFunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    emit AtSum();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit AtSubstract();
}

void MainWindow::on_pushButton_3_clicked()
{
    emit AtMultiple();
}

void MainWindow::on_pushButton_4_clicked()
{
    emit AtDivide();
}

void MainWindow::OnSumFunction()
{
    test.sum_value = test.SumCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.sum_value));
}

void MainWindow::OnSubstractFunction()
{
    test.substract_value = test.SubstractCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.substract_value));
}

void MainWindow::OnMultipleFunction()
{
    test.multiple_value = test.MultipleCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.multiple_value));
}

void MainWindow::OnDivideFunction()
{
    test.divide_value = test.DivideCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.divide_value));
}

double MainWindow::ValueCalc1()
{
    QString value = ui->textEdit->toPlainText();
    test.first_value = value.toDouble();

    return test.first_value;
}

double MainWindow::ValueCalc2()
{
    QString value = ui->textEdit_2->toPlainText();
    test.second_value = value.toDouble();

    return test.second_value;
}
