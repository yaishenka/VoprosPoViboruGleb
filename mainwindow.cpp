#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->NValue->setReadOnly(false);
    ui->nValue->setReadOnly(false);
    ui->pValue->setReadOnly(false);
    _customPlot = ui->customPlot;

    _binomDistr = std::make_shared<distribution::BinomialDistribution>();
    _poissonDistr = std::make_shared<distribution::PoissonDistribution>();
    _gaussDistr = std::make_shared<distribution::GaussDistribution>();

    _customPlot->addGraph();
    _customPlot->addGraph();
    _customPlot->addGraph();

    ui->binomialDistr->setAutoFillBackground(false);
    QPalette p = ui->binomialDistr->palette();
    p.setColor(QPalette::Button, _binomDistr->color());
    ui->binomialDistr->setPalette(p);

    ui->poissonDistr->setAutoFillBackground(false);
    p = ui->poissonDistr->palette();
    p.setColor(QPalette::Button, _poissonDistr->color());
    ui->poissonDistr->setPalette(p);

    ui->gaussDistr->setAutoFillBackground(false);
    p = ui->gaussDistr->palette();
    p.setColor(QPalette::Button, _gaussDistr->color());
    ui->gaussDistr->setPalette(p);

    _binomDistr->setGraph(_customPlot->graph(0));
    _poissonDistr->setGraph(_customPlot->graph(1));
    _gaussDistr->setGraph(_customPlot->graph(2));

    connect (ui->binomialDistr, &QCheckBox::stateChanged, this, &MainWindow::setBinomialDistribution);
    connect(ui->poissonDistr, &QCheckBox::stateChanged, this, &MainWindow::setPoissonDistribution);
    connect(ui->gaussDistr, &QCheckBox::stateChanged, this, &MainWindow::setGaussDistribution);
    connect (ui->NValue, QOverload<int>::of(&QSpinBox::valueChanged), _binomDistr.get(), &distribution::AbstractDistribution::setN);

    connect (ui->nValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _binomDistr.get(), &distribution::AbstractDistribution::setn);
    connect (ui->pValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _binomDistr.get(), &distribution::AbstractDistribution::setp);
    connect (ui->NValue, QOverload<int>::of(&QSpinBox::valueChanged), _poissonDistr.get(), &distribution::AbstractDistribution::setN);
    connect (ui->nValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _poissonDistr.get(), &distribution::AbstractDistribution::setn);
    connect (ui->pValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _poissonDistr.get(), &distribution::AbstractDistribution::setp);
    connect (ui->NValue, QOverload<int>::of(&QSpinBox::valueChanged), _gaussDistr.get(), &distribution::AbstractDistribution::setN);
    connect (ui->nValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _gaussDistr.get(), &distribution::AbstractDistribution::setn);
    connect (ui->pValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged), _gaussDistr.get(), &distribution::AbstractDistribution::setp);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::reset() {
    _customPlot->yAxis->rescale(true);
    _customPlot->yAxis->scaleRange(1.2);
    _customPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
}

void MainWindow::setBinomialDistribution(bool visible) {
    ui->binomialDistr->setAutoFillBackground(visible);
    _binomDistr->setGraphVisible(visible);
    reset();

}

void MainWindow::setPoissonDistribution(bool visible) {
    ui->poissonDistr->setAutoFillBackground(visible);
    _poissonDistr->setGraphVisible(visible);
    reset();
}

void MainWindow::setGaussDistribution(bool visible) {
    ui->gaussDistr->setAutoFillBackground(visible);
    _gaussDistr->setGraphVisible(visible);
    reset();
}


