#include "BinominalDistribution.h"

using namespace distribution::binominal;
void BinominalDistribution::calculateData () {
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
}
double BinominalDistribution::factorial(int n) {
    if (n == 0 || n ==1) return 1;
    double result(1);
    for ( int i = 2; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}
double BinominalDistribution::power (double base, int st) {
    if (base == 0) return 0;
    if (base == 1) return 1;
    double result(1);
    for ( int i = 1 ; i <= st; i++)
    {
        result = result * base;
    }
    return result;
}

void BinominalDistribution::setN(int value) {
    if (_N == value) {
        return;
    }
    _N = value;
    calculateData();
}

void BinominalDistribution::setn(double value) {
    if (_n == value) {
        return;
    }
    _n = value;
    calculateData();
}

void BinominalDistribution::setp(double value) {
    if (_p == value) {
        return;
    }
    _p = value;
    calculateData();
}
