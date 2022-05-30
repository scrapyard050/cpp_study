// MARK: системные хедары
#include <iostream>
#include <memory>

// MARK: пользовательские хедары
#include "statistic.h"
#include "min.h"
#include "max.h"
#include "mean.h"
#include "std_eval.h"

using StatisticPtr = std::shared_ptr<Statistic>;

/// выводим обьект на консоль
std::ostream& operator<<(std::ostream& os, const StatisticPtr data)
{
    os << data->name()<<" = "<<data->value()<<std::endl;
    return os;
}

void info(StatisticPtr data) {
    std::cout<<data;
}

int main(int argv, const char** argc)
{
    Data data;
    /// @todo можно было бы прочитать через цикл for чтобы переменная не ушла за область видимости цикла
    ///     for( int number = 0; std::cin >> number;)
    ///         data.push_back(number);
    
    // но мне кажется так код компактней и более читаемый
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(data));
    
    /// @todo работать с сырыми указателями небезопасно, поэтому работаем с умными указателями,
    /// из условия задачи непонятно нужно замерять время работы полиморфных функций или нет
    
    /// минимальном значении
    StatisticPtr min = std::make_shared<Min>(data);
    info(min);
    
    /// максимальное
    StatisticPtr max = std::make_shared<Max>(data);
    info(max);
    
    /// среднее арифмитическое
    StatisticPtr mean = std::make_shared<Mean>(data);
    info(mean);
    
    /// среднеквадратическое отклонение
    StatisticPtr std_eval = std::make_shared<StdEval>(data);
    info(std_eval);
    
    return 0;
}
