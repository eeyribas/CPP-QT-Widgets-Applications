#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void RealTimeData();

private:
    Ui::MainWindow *ui;

    QTimer data_timer;
    int color_variable;
};

#endif // MAINWINDOW_H
