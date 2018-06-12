#include "distributions/GaussDistribution.h"

using namespace distribution;

void GaussDistribution::calculateData() {
    if (_n != _max) {
        _max = _n;
        emit maxChanged(_max);
    }
    QVector <QPair<int,double>> result;
    double temp(0);
    double sigma = _N * _p * (1 - _p);
    double under_root = 2* 3.1415926 * sigma;
    double pre_calc1 = 1/sqrt(under_root);
    double pre_calc2 = -1/(2*sigma);

    for ( int i = 0; i < _n; i++)
    {
        temp =pre_calc1 * exp((i-_N*_p)*(i - _N*_p)*pre_calc2);
        result.push_back(qMakePair(i, temp));
        if (i < _min) {
            _min = i;
            emit minChanged(i);
        }
    }
    _data = std::make_shared<QVector <QPair<int,double>>>(result);
    emit dataReady(_data);
    resetGraphData();
}
