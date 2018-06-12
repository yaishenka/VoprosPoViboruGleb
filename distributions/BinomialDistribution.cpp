#include "distributions/BinomialDistribution.h"

using namespace distribution;
void BinomialDistribution::calculateData () {
    double W(0);
    if (_n != _max) {
        _max = _n;
        emit maxChanged(_max);
    }
    QVector <QPair<int,double>> result;
    for ( int i = 0; i < _n; i++) {
        W = factorial(_N)/(factorial(i)*factorial((_N-i)))*power(_p,i)*power((1-_p),(_N-i));
        result.push_back(qMakePair(i,W));
        if (i < _min) {
            _min = i;
            emit minChanged(i);
        }
    }
    _data = std::make_shared<QVector <QPair<int,double>>>(result);
    emit dataReady (_data);
    resetGraphData();
}

