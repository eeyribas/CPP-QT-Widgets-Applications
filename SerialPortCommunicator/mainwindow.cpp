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

    serial_port.Close();
}

void MainWindow::on_pushButton_clicked()
{
    bool state = serial_port.Open("/dev/serial0", 3000000);
    if (state == true)
        ui->label->setText("Connect");
    else
        ui->label->setText("Not Connect");
}

void MainWindow::on_pushButton_2_clicked()
{
    unsigned char buffer[5];
    uint value_1 = ui->lineEdit->text().toUInt();
    buffer[0] = (unsigned char)value_1;
    uint value_2 = ui->lineEdit_2->text().toUInt();
    buffer[1] = (unsigned char)value_2;
    uint value_3 = ui->lineEdit_3->text().toUInt();
    buffer[2] = (unsigned char)value_3;
    uint value_4 = ui->lineEdit_4->text().toUInt();
    buffer[3] = (unsigned char)value_4;
    uint value_5 = ui->lineEdit_5->text().toUInt();
    buffer[4] = (unsigned char)value_5;
    serial_port.Write(buffer, 5);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}
