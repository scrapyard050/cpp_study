#include <algorithm>
#include "min.h"
Min::Min(const Data& data): Statistic(data) {}

const char* Min::name() const {
    return "min";
}

double Min::value() const  {
    return *std::min_element(m_data.begin(), m_data.end());
}
