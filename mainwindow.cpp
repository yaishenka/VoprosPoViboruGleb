#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _customPlot = ui->customPlot;
    _binomDistr = std::make_shared<distribution::binominal::BinominalDistribution>();
    ui->NValue->setReadOnly(true);
    ui->nValue->setReadOnly(true);
    ui->pValue->setReadOnly(true);
    connect (ui->binominalDistr, &QAbstractButton::pressed, this, &MainWindow::setBinominalDistribution);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateCustomPlotData(std::shared_ptr<QVector<QPair<int, double>>> data) {
    _customPlot->addGraph();
    _customPlot->graph(0)->setData(QVector<double>(), QVector<double>());
    for (auto p : *data.get()) {
        qDebug() << p;
        _customPlot->graph(0)->addData(p.first, p.second);
    }
    _customPlot->xAxis->setRangeLower(_currentDistr->min());
    _customPlot->xAxis->setRangeUpper(_currentDistr->max());
    _customPlot->yAxis->rescale(true);
    _customPlot->yAxis->scaleRange(1.2);
    _customPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
}

void MainWindow::setBinominalDistribution() {
    if (_currentDistr == _binomDistr) {
        return;
    }
    if (_currentDistr) {
        disconnect(ui->NValue, nullptr, _currentDistr.get(), nullptr);
        disconnect(ui->nValue, nullptr, _currentDistr.get(), nullptr);
        disconnect(ui->pValue, nullptr, _currentDistr.get(), nullptr);
        disconnect(_currentDistr.get(), nullptr,this, nullptr);
    }
    _currentDistr = _binomDistr;
    ui->NValue->setReadOnly(false);
    ui->nValue->setReadOnly(false);
    ui->pValue->setReadOnly(false);
    connect (ui->NValue, QOverload<int>::of(&QSpinBox::valueChanged), _currentDistr.get(), &distribution::AbstractDistributon::setN);
    connect (ui->nValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _currentDistr.get(), &distribution::AbstractDistributon::setn);
    connect (ui->pValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _currentDistr.get(), &distribution::AbstractDistributon::setp);
    connect (_currentDistr.get(), &distribution::AbstractDistributon::dataReady, this, &MainWindow::updateCustomPlotData);
    connect (_currentDistr.get(), &distribution::AbstractDistributon::minChanged, this, &MainWindow::resisePlot);
    connect (_currentDistr.get(), &distribution::AbstractDistributon::maxChanged, this, &MainWindow::resisePlot);
    _currentDistr->calculateData();
}

void MainWindow::resisePlot(double value) {
    if (_customPlot->graphCount()) {
        _customPlot->xAxis->setRangeLower(_currentDistr->min());
        _customPlot->xAxis->setRangeUpper(_currentDistr->max());
        _customPlot->yAxis->rescale(true);
        _customPlot->yAxis->scaleRange(1.2);
        _customPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    }
}

