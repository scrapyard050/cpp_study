#include <numeric>
#include<cmath>
#include "std_eval.h"
StdEval::StdEval(const Data& data): Statistic(data) {}

const char* StdEval::name() const {
    return "std";
}

double StdEval::value() const  {
    auto sum = std::accumulate(m_data.begin(), m_data.end(), 0);
    auto middle_value = sum /m_data.size();
    Data tmp;
    std::for_each(m_data.begin(), m_data.end(), [&](auto const number) {
        int result = number - middle_value;
        result = pow(result, 2);
        tmp.push_back(result);
    });
    
    auto new_sum = std::accumulate(tmp.begin(), tmp.end(), 0);
    double value = new_sum/tmp.size();
    return sqrt(value);
    
    
}
