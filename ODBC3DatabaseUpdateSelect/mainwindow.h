#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <unistd.h>
#include "thread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void OnValueChanged();

private:
    Ui::MainWindow *ui;

    void Update(QString request);
    QString Select(QString request);

    Thread *thread;
    QSqlDatabase db;
    QString dsn;
    QStandardItemModel *standard_item_model;
};

#endif // MAINWINDOW_H
