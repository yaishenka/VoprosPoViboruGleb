#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <qcustomplot.h>
#include "distributions/BinomialDistribution.h"
#include "distributions/PoissonDistribution.h"
#include "distributions/GaussDistribution.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void updateCustomPlotData(std::shared_ptr<QVector<QPair<int, double>>> data);

    void setBinomialDistribution(bool visible);

    void setPoissonDistribution(bool visible);

    void setGaussDistribution(bool visible);

    void reset();

//    void resisePlot(double value);


private:
    Ui::MainWindow *ui;
    QCustomPlot* _customPlot;
    std::shared_ptr<distribution::BinomialDistribution> _binomDistr;
    std::shared_ptr<distribution::PoissonDistribution> _poissonDistr;
    std::shared_ptr<distribution::GaussDistribution> _gaussDistr;
//    std::shared_ptr<distribution::AbstractDistribution> _currentDistr;

};

#endif // MAINWINDOW_H
