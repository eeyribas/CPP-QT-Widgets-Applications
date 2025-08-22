#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                   Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/image.ico"));

    connect(ui->pushButton, SIGNAL(clicked()),
            SLOT(showMinimized()));
    connect(ui->pushButton_2, SIGNAL(clicked()),
            SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
