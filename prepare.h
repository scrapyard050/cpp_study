#pragma once

#include <iostream>

/// @brief Структура используется для возвращения нескольких значения
struct Params {
    bool showTable;
    bool showMinAttemps;
    int max_value;
};

/// @brief Функция выполняет подготовительные действия, парсит аргументы командной строки и выставляет значения параметров для работы
///
Params Prepare(int argv, const char** argc);
