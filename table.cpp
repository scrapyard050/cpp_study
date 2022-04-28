#include <fstream>
#include "table.h"
namespace {
// имя файла
const std::string file_name = "score_statistic.txt";
// подготавливаем файл на чтение
bool PrepareFileForrRead(std::ifstream& io_file)
{
    if( !io_file.is_open())
    {
        std::cout<<"Error open file for reading, maybe file is not exists";
        return false;
    }
    
    // перед началом чтения переводим курсор в начала файла
    io_file.seekg(0);
    return true;
}
};

void ShowPlayerStart( const CountAttempsResult& result )
{
    for(const auto& [player, attemps] : result)
    {
        std::cout<<"User name: "<<player<<std::endl;
        std::cout<<"Attempts: "<< attemps<<std::endl;
    }
}

// запоминаем игроков, кто сделал минимальное количество попыток при угадывании числа
bool ShowMinAttemps()
{
    std::ifstream io_file(file_name);
    if(!PrepareFileForrRead(io_file))
    {
        return false;
    }
    
    // строка прочитанная из файла
    std::string str;
    // флаг определяет необходимость проверки количества попыток
    bool checkScores = false;
    // флаг определяет первую итерацию
    bool firstStep = true;
    // имя игрока
    std::string name;
    // количество попыток
    int attempts = 0;
    // результаты
    CountAttempsResult result;
    while (std::getline(io_file, str )) {
        auto posResult = str.find(':');
        auto pos = str.find(' ');
        auto sub = str.substr(0, pos);
       
        // определяем пользователя в строке и вычитываем его
        if( sub == "User" )
        {
            name = str.substr( posResult + 1, str.length());
            checkScores = result.count(name) > 0 ? true : false;
            continue;
        }
        
        // определяем количество попыток на первом шаге
        if( firstStep)
        {
            attempts = atoi( str.substr( posResult + 1, str.length()).c_str());
            result.insert(std::make_pair(name, attempts));
            firstStep = false;
            continue;
        }
        
        
        // читаем количество попыток
        attempts = atoi( str.substr( posResult + 1, str.length()).c_str());
        // если пользователь уже ранее осуществлял ввод, то проверяем необходимость проверки количества попыток
        if( checkScores && attempts < result[name] )
        {
            result[name] = attempts;
            continue;
        }
        
        result.insert(std::make_pair(name, attempts));
    }
    
    io_file.close();
    // отображаем информацию
    ShowPlayerStart(result);
    return true;
}

// Чтение идет из файла, поскольку требований к файлу нет, то считаем то функции сам знают имя и путь к файлу для чтения и записи
// Также из условия задачи не понял, надо прочитать отдельную запись или файл целиком, сейчас читаем файл целиком
bool ShowTable()
{
    // файловый поток для работы с файлом
    std::ifstream io_file(file_name);
    if(!PrepareFileForrRead(io_file))
    {
        return false;
    }
    std::string str;
    while (std::getline(io_file, str)) {
        std::cout<<str<<std::endl;
    }
    
    io_file.close();
    return true;
}

bool WrireData(const std::string& info)
{
    if( info.empty())
    {
        std::cout<<"Data for record is empty"<<std::endl;
        return false;
    }
    
    std::ofstream io_file(file_name, std::ios::app);
    if( !io_file.is_open())
    {
        std::cout<<"Error open file for writing, maybe file is not exists";
        return false;
    }
    
    io_file<<info<<std::endl;
    io_file.flush();
    io_file.close();
    return true;
}
