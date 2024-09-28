#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "test.h"

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
    void AtSum();
    void AtSubstract();
    void AtMultiple();
    void AtDivide();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void OnSumFunction();
    void OnSubstractFunction();
    void OnMultipleFunction();
    void OnDivideFunction();

private:
    Ui::MainWindow *ui;

    double ValueCalc1();
    double ValueCalc2();

    Test test;
};

#endif // MAINWINDOW_H
