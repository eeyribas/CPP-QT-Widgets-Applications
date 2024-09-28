#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString DRIVER("QODBC3");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        ui->label->setText("Found");

        QString host_name = "localhost";
        QString dsn = QString("DRIVER={Firebird/InterBase(r) driver};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(host_name).arg("D:\\DatabaseFiles\\Shade_B.FDB");
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3", "firebirdDB");
        db.setConnectOptions();
        db.setDatabaseName(dsn);
        db.setHostName(host_name);
        db.setUserName("SYSDBA");
        db.setPassword("masterkey");

        if (db.open())
            ui->label->setText("Connected.");
        else
            ui->label->setText(db.lastError().text());
    } else {
        ui->label->setText("Not Found.");
    }
}
