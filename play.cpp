#include "play.h"
#include "table.h"
bool Play(int max_value)
{
    std::srand(std::time(nullptr));
    const int rand_value = std::rand() % max_value;
    
    std::string name;
    std::cout<<"User name: "<<std::endl;
    std::cin >> name;
    
    if( !WrireData("User name: " + name) )
    {
        return false;
    }
    
    int attempts = 0;
    do
    {
        attempts++;
        int value = 0;
        std::cout<<"Input value: "<<std::endl;
        std::cin>>value;
        if( value < rand_value)
        {
            std::cout<<"less"<<std::endl;
            continue;
        }
        
        if( value > rand_value)
        {
            std::cout<<"greater"<<std::endl;
            continue;
        }

        std::cout<<"win"<<std::endl;
        break;
    }while(true);
    
    return WrireData("Attempts: " + std::to_string(attempts));
}
