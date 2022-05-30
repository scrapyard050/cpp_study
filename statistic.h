#pragma once
#include <vector>

using Data = std::vector<int>;
class Statistic {
public:
    Statistic(const Data& data) : m_data(data) {}
    virtual ~Statistic() = default;
    virtual const char* name() const = 0;
    virtual double value() const = 0;
protected:
    Data m_data;
};


