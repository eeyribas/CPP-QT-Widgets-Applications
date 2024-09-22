#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

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
    void UploadProgress(qint64 byte_sents, qint64 byte_totals);
    void ReplyFinished(QNetworkReply*);
    void LoadError(QNetworkReply::NetworkError);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QFile *file;
    QNetworkAccessManager *network_access_manager;
    QNetworkReply *network_reply;
};

#endif // MAINWINDOW_H
