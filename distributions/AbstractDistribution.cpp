#include "distributions/AbstractDistribution.h"

using namespace distribution;

double AbstractDistribution::factorial(int n) {
    if (n == 0 || n ==1) return 1;
    double result(1);
    for ( int i = 2; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}
double AbstractDistribution::power (double base, int st) {
    if (base == 0) return 0;
    if (base == 1) return 1;
    double result(1);
    for ( int i = 1 ; i <= st; i++)
    {
        result = result * base;
    }
    return result;
}

void AbstractDistribution::setN(int value) {
    if (_N == value) {
        return;
    }
    _N = value;
    calculateData();
}

void AbstractDistribution::setn(double value) {
    if (_n == value) {
        return;
    }
    _n = value;
    calculateData();
}

void AbstractDistribution::setp(double value) {
    if (_p == value) {
        return;
    }
    _p = value;
    calculateData();
}

void AbstractDistribution::setGraph(QCPGraph* graph) {
    if (_graph == graph) {
        return;
    }
    if (_graph != nullptr) {
        deleteGraphData();
    }
    _graph = graph;
}

void AbstractDistribution::setGraphVisible(bool visible) {
    if (!_graph) {
        return;
    }
    _graph->setVisible(visible);
    if (!visible) {
        qDebug() << "here";
        deleteGraphData();
    } else {
        _graph->setPen(QPen(color()));
        calculateData();
        resetGraphData();
    }
}

void AbstractDistribution::deleteGraphData() {
    _graph->data()->clear();
}
void AbstractDistribution::resetGraphData() {
    if (!_graph) {
        return;
    }
    if (!_graph->visible()) {
        return;
    }
    _graph->setData(QVector<double>(), QVector<double>());
    for (auto p : *_data.get()) {
        _graph->addData(p.first, p.second);
    }
    _graph->parentPlot()->xAxis->setRangeLower(_min);
    _graph->parentPlot()->xAxis->setRangeUpper(_max);
    _graph->parentPlot()->yAxis->rescale(true);
    _graph->parentPlot()->yAxis->scaleRange(1.2);
    _graph->parentPlot()->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
}
