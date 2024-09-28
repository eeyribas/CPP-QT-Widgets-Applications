#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QSignalMapper>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnHandleButton(int button_id);

private:
    Ui::MainWindow *ui;

    QPushButton *push_buttons[10];
    bool buttons_state[10];
    QSignalMapper *signal_mapper;
};

#endif // MAINWINDOW_H
