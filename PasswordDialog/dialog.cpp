#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString password = "asd";
    QString read_text = ui->lineEdit->text();
    if (read_text == password) {
        ui->label->setText("True");
        close();
        emit AtData("Entering..");
    } else {
        ui->label->setText("Error");
    }
}
