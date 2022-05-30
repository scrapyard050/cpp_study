#pragma once
#include "statistic.h"

class Mean: public Statistic {
public:
    Mean(const Data& data);
    virtual const char* name() const override;
    virtual double value() const override;
    virtual ~Mean() = default;
};
