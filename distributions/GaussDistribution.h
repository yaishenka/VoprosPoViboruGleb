#pragma once
#include "distributions/AbstractDistribution.h"

namespace distribution {
        class GaussDistribution : public AbstractDistribution {
            Q_OBJECT
            public:
                void calculateData () override;
                QString name () const override {return "GaussDistribution"; }
                QColor color () const override {return QColor(76, 185, 181); }
        };
}



