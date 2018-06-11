#pragma once

#include <QVector>
#include <QPair>
#include <limits>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
#include <memory>

namespace distribution {
    class AbstractDistributon: public QObject {
        Q_OBJECT
        Q_PROPERTY(double min READ min NOTIFY minChanged)
        Q_PROPERTY(double max READ max NOTIFY minChanged)
        public:
            virtual void calculateData () = 0;
            virtual std::shared_ptr<QVector<QPair<int, double>>> data () const = 0;

            virtual void setN (int value) = 0;
            virtual void setn (double value) = 0;
            virtual void setp (double value) = 0;

            virtual double min () const = 0;
            virtual double max () const = 0;

        signals:
            void minChanged (double min);
            void maxChanged (double max);
            void dataReady (std::shared_ptr<QVector<QPair<int, double>>> data);
    };
}
