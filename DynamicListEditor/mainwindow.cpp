#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string_list_model = new QStringListModel(this);

    QStringList string_list;
    string_list << "Clair de Lune" << "Reverie" << "Prelude";

    string_list_model->setStringList(string_list);
    ui->listView->setModel(string_list_model);
    ui->comboBox->setModel(string_list_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                  QAbstractItemView::DoubleClicked);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (string_list_model)
        delete string_list_model;
}

void MainWindow::on_pushButton_clicked()
{
    int row = string_list_model->rowCount();
    string_list_model->insertRows(row, 1);
    QModelIndex model_index = string_list_model->index(row);

    ui->listView->setCurrentIndex(model_index);
    ui->listView->edit(model_index);
}

void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->listView->currentIndex().row();
    string_list_model->insertRows(row, 1);
    QModelIndex model_index = string_list_model->index(row);

    ui->listView->setCurrentIndex(model_index);
    ui->listView->edit(model_index);
}

void MainWindow::on_pushButton_3_clicked()
{
    string_list_model->removeRows(ui->listView->currentIndex().row(), 1);
}
