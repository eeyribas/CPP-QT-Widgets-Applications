#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(atSum()),
            this, SLOT(SumFunction()));
    connect(this, SIGNAL(atSubstract()),
            this, SLOT(SubstractFunction()));
    connect(this, SIGNAL(atMultiple()),
            this, SLOT(MultipleFunction()));
    connect(this, SIGNAL(atDivide()),
            this, SLOT(DivideFunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    emit atSum();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit atSubstract();
}

void MainWindow::on_pushButton_3_clicked()
{
    emit atMultiple();
}

void MainWindow::on_pushButton_4_clicked()
{
    emit atDivide();
}

void MainWindow::SumFunction()
{
    test.sum_value = test.SumCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.sum_value));
}

void MainWindow::SubstractFunction()
{
    test.substract_value = test.SubstractCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.substract_value));
}

void MainWindow::MultipleFunction()
{
    test.multiple_value = test.MultipleCalc(ValueCalc1(), ValueCalc2());
    ui->textEdit_3->setText(QString::number(test.multiple_value));
}

void MainWindow::DivideFunction()
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
