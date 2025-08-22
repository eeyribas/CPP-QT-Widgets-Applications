#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const QString DRIVER("QODBC3");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        ui->label->setText("Database Driver found.");

        QString host_name = "localhost";
        QString dsn = QString("DRIVER={Firebird/InterBase(r) driver};SERVER=%1;"
                              "DATABASE=%2;Trusted_Connection=Yes;").arg(host_name).
                              arg("D:\\DatabaseFiles\\Shade_B.FDB");
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
    } else {
        ui->label->setText("Database Driver doesn't find.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    if (thread)
        delete thread;

    if (standard_item_model)
        delete standard_item_model;
}

void MainWindow::OnValueChanged()
{
    if (db.open()) {
        ui->label_2->setText("Database connected.");

        QString insert_str = "select *from api_communication.add_('Server', '2020/06/12/11:20:54');";
        QSqlQuery insert_query(db);
        insert_query.exec(insert_str);
        QSqlDatabase::database().commit();

        QStringList list;
        QSqlQuery list_query(db);
        list_query.exec("select *from communication_tb;");
        while (list_query.next()) {
            list.append(list_query.value(0).toString());
            list.append(list_query.value(1).toString());
            list.append(list_query.value(4).toString());
        }

        QSqlDatabase::database().commit();

        standard_item_model = new QStandardItemModel(list.size() / 3, 3, this);
        standard_item_model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        standard_item_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Value"));
        standard_item_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        int count = 0;
        for (int row = 0; row < list.size() / 3; row++) {
            for (int col = 0; col < 3; col++) {
                QModelIndex index = standard_item_model->index(row,col,QModelIndex());
                standard_item_model->setData(index, list[count]);
                count++;
            }
        }
        ui->tableView->setModel(standard_item_model);

        db.close();
    } else {
        ui->label_2->setText("Database doesn't connect.");
        ui->label_3->setText(db.lastError().text());
        thread->stop = true;
    }
}
