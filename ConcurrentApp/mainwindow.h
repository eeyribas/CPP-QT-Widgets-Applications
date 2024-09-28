#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrent/QtConcurrent>
#include "job.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void AtStop1();
    void AtStop2();

public slots:
    void OnNewNumber1(QString name, int number);
    void OnNewNumber2(QString name, int number);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    Job *job_1;
    Job *job_2;
};

#endif // MAINWINDOW_H
