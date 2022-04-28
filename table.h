#pragma once
#include <iostream>
#include <map>

using CountAttempsResult = std::map<std::string, int>;

/// @brief Отображает статистику игры
///
bool ShowTable();
/// @brief Пишем в файл
///
bool WrireData(const std::string& info);
/// @brief Возвращает информацию по минималным попытка ввода
///
bool ShowMinAttemps();

