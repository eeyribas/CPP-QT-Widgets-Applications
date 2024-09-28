#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    signal_mapper = new QSignalMapper(this);
    QWidget *widget = new QWidget();
    widget->setStyleSheet("QWidget { background-color: rgb(94, 94, 94); }");
    ui->scrollArea->setWidget(widget);

    QFormLayout *form_layout = new QFormLayout();
    widget->setLayout(form_layout);

    for (int i = 0; i < 10; i++) {
        push_buttons[i] = new QPushButton(this);
        push_buttons[i]->setStyleSheet("QPushButton { background-color: rgb(94, 94, 94); border: 1px solid black; border-radius: 5px; width: 45px; height: 45px; } QPushButton:hover { background-color: rgb(194, 194, 194); }");
        buttons_state[i] = false;
        signal_mapper->setMapping(push_buttons[i], i);
        connect(push_buttons[i], SIGNAL(clicked()),
                signal_mapper, SLOT(map()));

        QLabel *label_1 = new QLabel();
        label_1->setGeometry(0, 0, 100, 40);
        label_1->setStyleSheet("QLabel { border: 0px; font-size: 14px; padding-left: 15px; color: rgb(240, 240, 240); }");
        label_1->setText("Text1");

        QLabel *label_2 = new QLabel();
        label_2->setGeometry(100, 0, 30, 40);
        label_2->setStyleSheet("QLabel { border: 0px; font-size: 14px; padding-left: 15px; color: rgb(240, 240, 240); }");
        label_2->setText("Text2");

        QWidget *tmp_widget = new QWidget();
        QHBoxLayout *tmp_h_layout = new QHBoxLayout();
        tmp_h_layout->addWidget(label_1);
        tmp_h_layout->addWidget(label_2);
        tmp_widget->setLayout(tmp_h_layout);
        tmp_widget->setStyleSheet("QWidget { border: 0px; } QWidget:hover { border: 2px solid white; }");

        form_layout->addRow(push_buttons[i], tmp_widget);
    }

    connect(signal_mapper, SIGNAL(mapped(int)),
            this, SLOT(OnHandleButton(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnHandleButton(int button_id)
{
    if (buttons_state[button_id] == false) {
        push_buttons[button_id]->setStyleSheet("QPushButton { background-color: rgb(194, 194, 194); border: 1px solid black; border-radius: 5px; width: 45px; height: 45px; }");
        buttons_state[button_id] = true;
    } else if(buttons_state[button_id] == true) {
        push_buttons[button_id]->setStyleSheet("QPushButton { background-color: rgb(94, 94, 94); border: 1px solid black; border-radius: 5px; width: 45px; height: 45px; } QPushButton:hover { background-color: rgb(194, 194, 194); }");
        buttons_state[button_id] = false;
    }
}
