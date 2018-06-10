#include "BinominalDistribution.h"

using namespace distribution::binominal;
QVector <QPair<int,double>> BinominalDistribution::calculateData () {
    double W(0);
    QVector <QPair<int,double>> result;
    for ( int i = 0; i < _n; i++) {
        W = factorial(_N)/(factorial(i)*factorial((_N-i)))*power(_p,i)*power((1-_p),(_N-i));
        result.push_back(qMakePair(i,W));
        if (i < _min) {
            _min = i;
            emit minChanged(W);
        }
        if (i > _max) {
            _max = i;
            emit maxChanged(W);
        }
    }
    return result;
    emit dataReady (result);
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
