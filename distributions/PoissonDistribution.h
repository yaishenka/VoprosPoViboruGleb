#pragma once
#include "distributions/AbstractDistribution.h"

namespace distribution {
        class PoissonDistribution : public AbstractDistribution {
            Q_OBJECT
            public:
                void calculateData () override;
                QString name () const override {return "PoissonDistribution"; }
                QColor color () const override {return Qt::red; }
        };
}



