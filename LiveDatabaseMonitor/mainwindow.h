#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include "thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OnValueChanged();

private:
    Ui::MainWindow *ui;

    Thread *thread;
    QSqlDatabase db;
    QString dsn;
    QStandardItemModel *standard_item_model;
};

#endif // MAINWINDOW_H
