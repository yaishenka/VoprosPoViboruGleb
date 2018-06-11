#pragma once

#include <QVector>
#include <QPair>
#include <limits>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
#include "AbstractDistribution.h"

namespace distribution {
        class PoissonDistribution : public AbstractDistribution {
            Q_OBJECT
            public:
                void calculateData () override;
                QString name () const override {return "PoissonDistribution"; }
        };
}



