#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _customPlot = ui->customPlot;
    _distr = std::make_shared<distribution::binominal::BinominalDistribution>();
    connect (ui->pushButton, &QAbstractButton::pressed, this, &MainWindow::on_pushButton_pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initCustomPlot () {
    _customPlot->xAxis->setRangeLower(0);
    _customPlot->xAxis->setRangeUpper(10);
}

void MainWindow::on_pushButton_pressed()
{
    _customPlot->addGraph();
    _customPlot->graph(0)->setData(QVector<double>(), QVector<double>());
    auto samples = _distr->calculateData();
    for (auto p : samples) {
        qDebug() << p;
        _customPlot->graph(0)->addData(p.first, p.second);
    }
    _customPlot->xAxis->setRangeLower(_distr->min());
    _customPlot->xAxis->setRangeUpper(_distr->max());
    _customPlot->yAxis->rescale(true);
    _customPlot->yAxis->scaleRange(1.2);
    _customPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
}
