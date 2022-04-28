#include "prepare.h"


Params Prepare(int argv, const char** argc)
{
    // ключи которые надо распарсить
    // определяет максимальное допустимое число
    const std::string max = "–max";
    // флаг определяет необходимость показывать все таблицы с результатами
    const std::string table = "-table";
    const std::string minAttemps = "-min_attemps";
   
    // параметры по умолчанию
    bool showTable = false;
    bool showMinAttemps = false;
    int max_value = 100;
    Params params;
    params.showTable = showTable;
    params.showMinAttemps = showMinAttemps;
    params.max_value = max_value;
    
    // если параметры не были переданы то возвращаем дефолтные значения
    if( argv == 1)
    {
        return params;
    }
    
    
    // проходимся по переданным параметрам
    for(int counter = 0; counter < argv; counter++)
    {
        std::string param(argc[counter]);
        if( table == param)
        {
            showTable = true;
            continue;
        }
        
        if( minAttemps == param)
        {
            showMinAttemps = true;
            continue;
        }
        
        if( max == param )
        {
            max_value = atoi(argc[counter+1]);
            continue;
        }
    }
    
    // выставляем распарсенные значения
    params.showTable = showTable;
    params.showMinAttemps = showMinAttemps;
    params.max_value = max_value;
}
