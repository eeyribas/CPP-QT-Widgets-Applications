#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    color_variable = 0;

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->widget->setBackground(QBrush(gradient));

    QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    QCPBars *nuclear = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    QCPBars *fossil = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

    regen->setAntialiased(false);
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);

    regen->setStackingGap(1);
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);

    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));

    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";

    QSharedPointer<QCPAxisTickerText> text_ticker(new QCPAxisTickerText);
    text_ticker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(text_ticker);
    ui->widget->xAxis->setTickLabelRotation(60);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 8);
    ui->widget->xAxis->setBasePen(QPen(Qt::white));
    ui->widget->xAxis->setTickPen(QPen(Qt::white));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabelColor(Qt::white);

    ui->widget->yAxis->setRange(0, 12.1);
    ui->widget->yAxis->setPadding(5);
    ui->widget->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->widget->yAxis->setBasePen(QPen(Qt::white));
    ui->widget->yAxis->setTickPen(QPen(Qt::white));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    QVector<double> fossil_data, nuclear_data, regen_data;
    fossil_data  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclear_data << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regen_data   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossil_data);
    nuclear->setData(ticks, nuclear_data);
    regen->setData(ticks, regen_data);

    ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);

    QFont legend_font = font();
    legend_font.setPointSize(10);
    ui->widget->legend->setFont(legend_font);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RealTimeData()
{
    static QTime time(QTime::currentTime());
    double key_time = time.elapsed()/1000.0;

    double val = 1;
    color_variable++;

    if (color_variable == 0) {
        ui->widget->graph()->setBrush(QBrush(QColor(255,0,0)));
    } else if (color_variable == 5000) {
        ui->widget->graph()->setBrush(QBrush(QColor(0,255,0)));
    } else if(color_variable == 10000) {
        ui->widget->graph()->setBrush(QBrush(QColor(0,0,255)));
        color_variable = 0;
    }

    ui->widget->graph(0)->addData(key_time, val);
    ui->widget->xAxis->rescale();
    ui->widget->replot();
}
