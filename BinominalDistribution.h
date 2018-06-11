#pragma once

#include <QVector>
#include <QPair>
#include <limits>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
#include "AbstractDistribution.h"


namespace distribution {
    namespace binominal {
        class BinominalDistribution : public distribution::AbstractDistributon {
            Q_OBJECT
            public:
                void calculateData () override;
                std::shared_ptr<QVector<QPair<int, double>>> data () const override {return _data; }

                double factorial(int n);
                double power (double base, int st);

                void setN (int value) override;
                void setn (double value) override;
                void setp (double value) override;


                double min () const override {return _min; }
                double max () const override {return _max; }



            signals:

            private:
                double _min = std::numeric_limits<double>::max();
                double _max = std::numeric_limits<double>::min();
                double _p = 0.5;
                int _N = 100;
                int _n = 10;
                std::shared_ptr<QVector<QPair<int, double>>> _data;
        };
    }
}



