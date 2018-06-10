#include <QVector>
#include <QPair>
#include <limits>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
namespace distribution {
    namespace binominal {
        class BinominalDistribution : public QObject {
            Q_OBJECT
            Q_PROPERTY(double min READ min NOTIFY minChanged)
            Q_PROPERTY(double max READ max NOTIFY minChanged)
            public:
                QVector <QPair<int,double>> calculateData ();
                double factorial(int n);
                double power (double base, int st);

                double min () const {return _min; }
                double max () const {return _max; }

            signals:
                void minChanged (double min);
                void maxChanged (double max);
                void dataReady (QVector<QPair<int, double>> data);
            private:
                double _min = std::numeric_limits<double>::max();
                double _max = std::numeric_limits<double>::min();
                double _p = 0.5;
                int _N = 100;
                int _n = 10;
        };
    }
}



