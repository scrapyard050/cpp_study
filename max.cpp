#include <algorithm>
#include "max.h"
Max::Max(const Data& data): Statistic(data) {}

const char* Max::name() const {
    return "max";
}

double Max::value() const  {
    return *std::max_element(m_data.begin(), m_data.end());
}
