#pragma once

#include "distributions/AbstractDistribution.h"



namespace distribution {
        class BinomialDistribution : public AbstractDistribution {
            Q_OBJECT
            public:
                void calculateData () override;
                QString name () const override {return "BinomialDistribution"; }
                QColor color () const override {return Qt::green; }
        };
}



