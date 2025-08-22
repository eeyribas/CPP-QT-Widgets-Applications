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
    void OnNumPressed();
    void OnMathButtonPressed();
    void OnEqualButtonPressed();
    void OnChangeNumberSign();
    void OnClearButtonPressed();

private:
    Ui::MainWindow *ui;

    double calc;
    bool divide_trigger;
    bool multiply_trigger;
    bool add_trigger;
    bool substract_trigger;
};

#endif // MAINWINDOW_H
