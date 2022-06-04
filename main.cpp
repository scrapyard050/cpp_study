#include <iostream>
#include "my_vector.h"
#include "my_list.h"

void my_vector_test()
{
    otus::vector<int> my_vector;
    my_vector.push_back(3);
    my_vector.push_back(30);
    my_vector.pop_back();
    my_vector.push_back(50);
    my_vector.push_back(100);
    my_vector.push_back(200);
    my_vector.push_back(200);
   // std::cout<<my_vector[0]<<std::endl;
    my_vector.print();
    std::cout<<"------"<<std::endl;
    my_vector.insert(1, 5);
    my_vector.print();
}

void my_list_test()
{
    otus::list<int> my_list;
    my_list.push_back(4);
    my_list.push_back(10);
    my_list.push_back(20);
    my_list.push_back(30);
    my_list.print();
    std::cout<<"------"<<std::endl;
    my_list.pop_back();
    my_list.print();
    std::cout<<"------"<<std::endl;
    std::cout<<my_list[0]<<std::endl;;
    std::cout<<"------"<<std::endl;
    my_list.insert(3, 5);
    my_list.print();

}
int main(int argv, char** argc)
{
        
    // тестирование вектора
    my_vector_test();
    
    // тестирование списка
    //my_list_test();
    return 0;
}
