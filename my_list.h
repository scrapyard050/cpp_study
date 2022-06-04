#pragma once
#include <iostream>

namespace otus {

/// @todo выберем структуру потому что считаем что все поля узла открыты
template<class T>
class Node
{
public:
    explicit Node(T value) : value_(value), next_(nullptr) {}
    Node* next_;
    T value_;
};

template<class T>
class list
{
public:
    list() : first_(nullptr), last_(nullptr) {}
    ~list()
    {
        delete first_;
        delete last_;
    }
    
    /// @todo из условия задачи не понял нужен ли конструтор копирования или нет
    /// пока что удалил его
    list(const list& other) = delete;
    list& operator =(const list& other) = delete;
    
    /// @brief Добавление элемента в конец списка
    void push_back(const T& value)
    {
        auto node = new Node(value);
        if( is_empty())
        {
            first_ = last_ = node;
            return;
        }
        
        last_->next_ = node;
        last_ = node;
    }
    
    /// @brief Вывод Содержимого списка
    void print()
    {
        if( is_empty())
        {
            return;
        }
        
        Node<T>* node = first_;
        while (node)
        {
            std::cout<<node->value_<<std::endl;
            node = node->next_;
        }
    }
    
    /// @brief Удаляем элемент с конца списка
    void pop_back()
    {
        // проверяем является ли список пустым
        if(is_empty())
        {
            return;
        }
        
        // проверяем возможно список состоит из одно элемента
        if( first_ == last_)
        {
            Node<T>* node = first_;
            first_ = node->next_;
            delete node;
            return;
        }
        
        // доходим до предпоследнего элемента
        Node<T>* node = first_;
        while( node -> next_ != last_)
        {
            node = node ->next_;
        }
        
        node->next_ = nullptr;
        delete last_;
        last_ = node;
    }
    
    // возвращение узла по индексу
    const Node<T>*  operator[](const int index) const
    {
        return find_by_index(index);
    }
    
    /// @brief вставляем данные по определенному индексу
    void insert(const int index, const T& data)
    {
        // пытаемся получить узел до указаного индекса
        Node<T>* node = find_by_index(index == 0 ? index : index - 1);
        // игнорируем попутку если список пустой или попытка вставить значение за пределами последнего элемента
        // потому что непонятно как быть в такой ситуации ведь обращение к элементам идет через указатели и если индекс невалиден то указатель будет nullptr
        // а если при таких событиях вставить в начало или конец списка то это вводит в заблуждение
        if( ! node )
        {
            std::cout<<"Invalid index"<<std::endl;
            return;
        }
        
        Node<T>*new_node = new Node<T>(data);
        if( node == first_ && index == 0)
        {
            new_node->next_ = first_;
            first_ = new_node;
            return;
        }
        
        Node<T>*tmp = node->next_;
        new_node->next_ = tmp;
        node->next_ = new_node;
       
    }
    
private:
    Node<T>* first_;
    Node<T>* last_;
    bool is_empty() const
    {
        if(first_ == nullptr )
        {
            return true;
        }
        
        return false;;
    }
    
    Node<T>* find_by_index(const int index) const
    {
        if( is_empty() )
        {
            return nullptr;
        }
       
       Node<T>* node = first_;
       for( size_t counter = 0; counter < index; counter++)
       {
           node = node -> next_;
           if(!node)
           {
               return nullptr;
           }
           
       }
       return node;
   }
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>* node )
{
    os<<node->value_<<std::endl;
    return os;
}
}// namespace otus
