#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include "BinominalDistribution.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateCustomPlotData(std::shared_ptr<QVector<QPair<int, double>>> data);

    void setBinominalDistribution();

    void resisePlot(double value);


private:
    Ui::MainWindow *ui;
    QCustomPlot* _customPlot;
    QPushButton *m_button;
    std::shared_ptr<distribution::binominal::BinominalDistribution> _binomDistr;
    std::shared_ptr<distribution::AbstractDistributon> _currentDistr;

};

#endif // MAINWINDOW_H
