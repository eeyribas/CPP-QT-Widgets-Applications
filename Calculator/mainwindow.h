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

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    void ClearButtonPressed();

private:
    Ui::MainWindow *ui;

    double calc = 0.0;
    bool divide_trigger = false;
    bool multiply_trigger = false;
    bool add_trigger = false;
    bool substract_trigger = false;
};

#endif // MAINWINDOW_H
