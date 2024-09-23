#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include <QDebug>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list = {"a", "as", "asd", "asda", "asdas", "asdasd", "asdasda"};

    QCompleter *completer = new QCompleter(list, this);
    completer->popup()->setStyleSheet("font: 18px 'Roboto'; background-color: rgb(194, 194, 194); color: rgb(0, 0, 0); border: 0px; padding-left: 2px; padding-right: 2px;");
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
