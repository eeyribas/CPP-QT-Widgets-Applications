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

    connect(dialog, SIGNAL(AtData(QString)),
            this, SLOT(OnDialogFunction(QString)));
}

void MainWindow::OnDialogFunction(QString text)
{
    ui->label->setText(text);
}
