#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    if (QSqlDatabase::isDriverAvailable(DRIVER))
        ui->label->setText("Database Driver found.");
    else
        ui->label->setText("Database Driver not find.");

    QString host_name = "localhost";
    QString dsn = QString("DRIVER={Firebird/InterBase(r) driver};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(host_name)
                  .arg("D:\\DatabaseFiles\\SHADE_READY_28_08_2020.FDB");
    db = QSqlDatabase::addDatabase("QODBC3", "firebirdDB");
    db.setConnectOptions();
    db.setDatabaseName(dsn);
    db.setHostName(host_name);
    db.setUserName("SYSDBA");
    db.setPassword("masterkey");

    thread = new Thread();
    thread->stop = false;
    connect(thread, SIGNAL(AtValueChanged()),
            this, SLOT(OnValueChanged()));
    thread->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    db.close();
    thread->stop = true;
    ui->label_2->setText("Database disconnect.");
}

void MainWindow::OnValueChanged()
{
    if (db.open()) {
        ui->label_2->setText("Database connected.");
        usleep(100000);

        QString update_request_1 = "select * from API_PROCESS_STATEMENT.set_set_process_state('F');";
        Update(update_request_1);
        QString update_request_2 = "select * from API_PROCESS_STATEMENT.set_set_process_id('RPI SET');";
        Update(update_request_2);
        QString update_request_3 = "select * from API_PROCESS_STATEMENT.set_get_process_state(T');";
        Update(update_request_3);
        QString update_request_4 = "select * from API_PROCESS_STATEMENT.set_get_process_id(200);";
        Update(update_request_4);

        QString select_request_1 = "select * from API_PROCESS_STATEMENT.get_set_process_state;";
        QString select_response_1 = Select(select_request_1);
        qDebug() << "Select Response - 1 = " << select_response_1;
        QString select_request_2 = "select * from API_PROCESS_STATEMENT.get_set_process_id;";
        QString select_response_2 = Select(select_request_2);
        qDebug() << "Select Response - 2 = " << select_response_2;
        QString select_request_3 = "select * from API_PROCESS_STATEMENT.get_get_process_state;";
        QString select_response_3 = Select(select_request_3);
        qDebug() << "Select Response - 3 = " << select_response_3;
        QString select_request_4 = "select * from API_PROCESS_STATEMENT.get_get_process_id;";
        QString select_response_4 = Select(select_request_4);
        qDebug() << "Select Response - 4 = " << select_response_4;

        db.close();
    } else {
        ui->label_2->setText("Database not connect.");
        ui->label_3->setText(db.lastError().text());
        thread->stop = true;
    }
}

void MainWindow::Update(QString request)
{
    QSqlQuery query(db);
    query.exec(request);
    while (query.next()){}

    QSqlDatabase::database().commit();
}

QString MainWindow::Select(QString request)
{
    QString response = "";

    QSqlQuery query(db);
    query.exec(request);
    while (query.next()) {
        response = query.value(0).toString();
    }

    QSqlDatabase::database().commit();

    return response;
}
