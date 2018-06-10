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
    void initCustomPlot();
    ~MainWindow();
    void on_pushButton_clicked();
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    QCustomPlot* _customPlot;
    QPushButton *m_button;
    std::shared_ptr<distribution::binominal::BinominalDistribution> _distr;

};

#endif // MAINWINDOW_H
