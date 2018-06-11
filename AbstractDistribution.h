#pragma once

#include <QVector>
#include <QPair>
#include <limits>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
#include <memory>
#include <cmath>
#include <QString>

namespace distribution {
    class AbstractDistribution: public QObject {
        Q_OBJECT
        Q_PROPERTY(double min READ min NOTIFY minChanged)
        Q_PROPERTY(double max READ max NOTIFY minChanged)
        public:
            virtual void calculateData () = 0;

            std::shared_ptr<QVector<QPair<int, double>>> data () const {return _data; }

            double factorial(int n);
            double power (double base, int st);

            void setN (int value);
            void setn (double value);
            void setp (double value);

            double min () const {return _min; }
            double max () const {return _max; }

            virtual QString name () const {return ""; }

        signals:
            void minChanged (double min);
            void maxChanged (double max);
            void dataReady (std::shared_ptr<QVector<QPair<int, double>>> data);
        protected:
            double _min = std::numeric_limits<double>::max();
            double _max = std::numeric_limits<double>::min();
            double _p = 0.5;
            int _N = 100;
            int _n = 10;
            std::shared_ptr<QVector<QPair<int, double>>> _data;

    };
}
