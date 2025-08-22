#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(AtButton()),
            this, SLOT(OnLabel1()));
    connect(this, SIGNAL(AtButton()),
            this, SLOT(OnLabel2()));
    connect(this, SIGNAL(AtButton()),
            this, SLOT(OnLabel3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    emit AtButton();
}

void MainWindow::on_pushButton_released()
{
    ui->label->setText("Released");
    ui->label_2->setText("Released");
    ui->label_3->setText("Released");
}

void MainWindow::OnLabel1()
{
    ui->label->setText("Slot-1");
}

void MainWindow::OnLabel2()
{
    ui->label_2->setText("Slot-2");
}

void MainWindow::OnLabel3()
{
    ui->label_3->setText("Slot-3");
}
