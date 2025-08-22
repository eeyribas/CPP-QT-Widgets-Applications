#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void AtButton();

private slots:
    void on_pushButton_pressed();
    void on_pushButton_released();
    void OnLabel1();
    void OnLabel2();
    void OnLabel3();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
