#pragma once
#include "statistic.h"

class StdEval: public Statistic {
public:
    StdEval(const Data& data);
    virtual const char* name() const override;
    virtual double value() const override;
};

