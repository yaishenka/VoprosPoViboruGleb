#include "AbstractDistribution.h"

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
