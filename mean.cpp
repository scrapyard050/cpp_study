#include <numeric>
#include "mean.h"
Mean::Mean(const Data& data): Statistic(data) {}

const char* Mean::name() const {
    return "mean";
}

double Mean::value() const  {
    auto sum = std::accumulate(m_data.begin(), m_data.end(), 0);
    return sum /m_data.size();
}
