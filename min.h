#pragma once
#include "statistic.h"

class Min: public Statistic {
public:
    Min(const Data& data);
    virtual const char* name() const override;
    virtual double value() const override;
};
