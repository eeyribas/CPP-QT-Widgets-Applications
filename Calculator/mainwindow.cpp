#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calc = 0.0;
    divide_trigger = false;
    multiply_trigger = false;
    add_trigger = false;
    substract_trigger = false;

    ui->lineEdit->setText(QString::number(calc));
    QPushButton *number_buttons[10];
    for (int i = 0; i < 10; ++i) {
        QString button_name = "pushButton_" + QString::number(i);
        number_buttons[i] = MainWindow::findChild<QPushButton *>(button_name);
        connect(number_buttons[i], SIGNAL(released()),
                this, SLOT(OnNumPressed()));
    }

    connect(ui->pushButton_10, SIGNAL(released()),
            this, SLOT(OnClearButtonPressed()));
    connect(ui->pushButton_11, SIGNAL(released()),
            this, SLOT(OnChangeNumberSign()));
    connect(ui->pushButton_12, SIGNAL(released()),
            this, SLOT(OnMathButtonPressed()));
    connect(ui->pushButton_13, SIGNAL(released()),
            this, SLOT(OnMathButtonPressed()));
    connect(ui->pushButton_14, SIGNAL(released()),
            this, SLOT(OnMathButtonPressed()));
    connect(ui->pushButton_15, SIGNAL(released()),
            this, SLOT(OnMathButtonPressed()));
    connect(ui->pushButton_19, SIGNAL(released()),
            this, SLOT(OnEqualButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnNumPressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString button_value = button->text();
    QString display_value = ui->lineEdit->text();

    if (display_value.toDouble() == 0.0) {
        ui->lineEdit->setText(button_value);
    } else {
        QString new_value = display_value + button_value;
        double db_new_value = new_value.toDouble();
        ui->lineEdit->setText(QString::number(db_new_value, 'g', 16));
    }
}

void MainWindow::OnMathButtonPressed()
{
    divide_trigger = false;
    multiply_trigger = false;
    add_trigger = false;
    substract_trigger = false;

    QString display_value = ui->lineEdit->text();
    calc = display_value.toDouble();

    QPushButton *button = (QPushButton*)sender();
    QString button_value = button->text();

    if (QString::compare(button_value, "/", Qt::CaseInsensitive) == 0)
        divide_trigger = true;
    else if (QString::compare(button_value, "*", Qt::CaseInsensitive) == 0)
        multiply_trigger = true;
    else if (QString::compare(button_value, "+", Qt::CaseInsensitive) == 0)
        add_trigger = true;
    else
        substract_trigger = true;

    ui->lineEdit->setText("");
}

void MainWindow::OnEqualButtonPressed()
{
    double solution = 0;
    QString display_value = ui->lineEdit->text();
    double db_display_value = display_value.toDouble();

    if (add_trigger == true)
        solution = calc + db_display_value;
    else if (substract_trigger == true)
        solution = calc - db_display_value;
    else if (multiply_trigger == true)
        solution = calc * db_display_value;
    else if (divide_trigger == true)
        solution = calc / db_display_value;

    ui->lineEdit->setText(QString::number(solution));
}

void MainWindow::OnChangeNumberSign()
{
    QString display_value = ui->lineEdit->text();

    QRegExp reg("[-]?[0-9.]");
    if (reg.exactMatch(display_value)) {
        double db_display_value = display_value.toDouble();
        double db_display_value_sign = -1 * db_display_value;
        ui->lineEdit->setText(QString::number(db_display_value_sign));
    }
}

void MainWindow::OnClearButtonPressed()
{
    ui->lineEdit->clear();
}
