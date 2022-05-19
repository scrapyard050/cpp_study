#pragma once
#include "statistic.h"

class Max: public Statistic {
public:
    Max(const Data& data);
    virtual const char* name() const override;
    virtual double value() const override;
};
