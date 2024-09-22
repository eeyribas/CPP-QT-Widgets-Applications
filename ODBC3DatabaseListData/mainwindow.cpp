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

void MainWindow::on_pushButton_1_clicked()
{
    const QString DRIVER("QODBC3");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {

        QString host_name = "localhost";
        dsn = QString("DRIVER={Firebird/InterBase(r) driver};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(host_name).arg("D:\\DatabaseFiles\\Example.FDB");
        db = QSqlDatabase::addDatabase("QODBC3", "direbirdDB");
        db.setConnectOptions();
        db.setDatabaseName(dsn);
        db.setHostName(host_name);
        db.setUserName("SYSDBA");
        db.setPassword("masterkey");

        if (db.open())
            ui->label_1->setText("Connected");
        else
            ui->label_1->setText("Not Connected");
    } else {
        ui->label_3->setText("Not Found");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    ui->label_1->setText("Disconnect");
}

void MainWindow::on_pushButton_3_clicked()
{
    QStringList list;

    QSqlQuery sql_query(db);
    sql_query.exec("select *from communication_tb;");
    while (sql_query.next()) {
        list.append(sql_query.value(0).toString());
        list.append(sql_query.value(1).toString());
        list.append(sql_query.value(4).toString());
     }

    ui->label_2->setText("Select");
    standard_item_model = new QStandardItemModel(list.size() / 3, 3, this);
    standard_item_model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    standard_item_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Value"));
    standard_item_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    int count = 0;
    for (int row = 0; row < list.size() / 3; row++) {
        for (int col = 0; col < 3; col++) {
            QModelIndex index = standard_item_model->index(row, col, QModelIndex());
            standard_item_model->setData(index, list[count]);
            count++;
        }
    }

    ui->tableView->setModel(standard_item_model);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString insert_string = "";
    insert_string.append("select *from api_communication.add_('");
    insert_string.append(ui->lineEdit->text());
    insert_string.append("', '2020/06/12/11:20:54');");

    QSqlQuery sql_query(db);
    sql_query.exec(insert_string);
    ui->label_3->setText("Add");
}
