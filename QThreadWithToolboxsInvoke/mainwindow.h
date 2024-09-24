#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread1.h"
#include "thread2.h"

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
    void on_pushButton_3_clicked();
    void OnValueChanged1();
    void OnValueChanged2();

private:
    Ui::MainWindow *ui;

    Thread1 *thread_1;
    Thread2 *thread_2;
    int counter_1;
    int counter_2;
};

#endif // MAINWINDOW_H
