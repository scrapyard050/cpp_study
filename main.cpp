#include <iostream>
#include "prepare.h"
#include "table.h"
#include "play.h"

int main(int argv, const char** argc)
{
    // поскольку работаем с примитивами то получаем копии
    auto [showTable, showMinAttemps, max_value] = Prepare(argv, argc);
    if( showTable )
    {
        // отображаем таблицу и выходим
        return !ShowTable();
    }
    if( showMinAttemps)
    {
        return !ShowMinAttemps();
    }
    
    // Угадываем число
    return !Play(max_value);
}
