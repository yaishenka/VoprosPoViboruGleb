#include "PoissonDistribution.h"

using namespace distribution;
void PoissonDistribution::calculateData () {
    if (_n != _max) {
        _max = _n;
        emit maxChanged(_max);
    }
    QVector <QPair<int,double>> result;
    double temp(0);
    double n = _N * _p;
    for ( int i = 0; i < _n; i++) {
        temp = power(n,i)/factorial(i)*exp((-1)*(n));
        result.push_back(qMakePair(i,temp));
        if (i < _min) {
            _min = i;
            emit minChanged(i);
        }
    }
    _data = std::make_shared<QVector <QPair<int,double>>>(result);
    emit dataReady(_data);
}

