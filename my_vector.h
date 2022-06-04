#pragma once

#include <stddef.h>
#include <cstring>
// Класс назвал как и методы класса с мальнокй буквы чтобы закосить под класс векто из стандартной либы
// Различаться же классы будут через пространство имен
namespace otus
{
template<class T>
class vector
{
public:
    /// @todo запрещаем неявное преобразование
    ///  чтобы не выделять память на каждый push_back выделяем некоторое количество заранее и в случае необходимости увеличиемва
    explicit vector(int capacity = 3): capacity_(capacity), size_(0)
    {
        dataPtr = new T[capacity_];
    }
    
    /// @todo из условия задачи не понял нужен ли конструтор копирования или нет
    /// пока что удалил его
    vector(const vector& other) = delete;
    vector& operator = (const vector& other)  = delete;
   
    /// @brief возвращаем элемент по индексу
    const T& operator[](int index) const
    {
        return dataPtr[index];
    }
    
    /// @brief освобожваем ресурс,  в данном случае память
    ~vector()
    {
        delete [] dataPtr;
    }
    
    
    /// @brief резервируем новую память
    void reserve(size_t size)
    {
        if(size < capacity_)
        {
            return;
        }
        
        T* tmp = dataPtr;
        dataPtr = new T[size];
        for( size_t counter = 0; counter < size; counter++)
        {
            dataPtr[counter] = tmp[counter];
            memset(dataPtr+size_, 0, size*sizeof(int) );
        }
        delete [] tmp;
    }
        
    void print()
    {
        for(size_t counter = 0; counter <size_; counter++)
        {
            std::cout<<dataPtr[counter]<<std::endl;
        }
    }
    
    /// @brief вставляем элемент в конец
    void push_back(const T& data)
    {
        if(size_ > capacity_)
        {
            capacity_ *=2;
            reserve(capacity_ + 1);
        }
        
        dataPtr[size_++] = data;
    }
    
    /// @brief удаляем элемент с конца
    void pop_back()
    {
        /// @todo для освобождения данных вызываю конструтор по умолчанию далее уменьшаем индекс
        /// не уверен, что это хорошая мысль но других идей нет
        dataPtr[size_ -1 ] = T();
        size_--;
    }
    
    /// @brief вставляем данные по определенному индексу
    void insert(int index, const T& data)
    {
        if(index > capacity_)
        {
            reserve(index + 1);
            size_ = index + 1;
            
        }
        size_t tmp1_size = size_ + 1;
        int tmp1[tmp1_size];
         memset(tmp1, 0, (tmp1_size)*sizeof(int));
        size_t counter = 0;
        size_t i = 0;
        for( ;counter <= index ; counter++, i++)
        {
            tmp1[counter] = dataPtr[counter];
            if(counter == index)
            {
                tmp1[index ] = data;
                break;
            }
        }
        
        counter++;
        for( ;counter <= size_; counter++, i++)
        {
            tmp1[counter] = dataPtr[i];
        }
        
        
        std::cout<<"t";
        
        
    }

private:
    size_t size_;
    size_t capacity_;
    T* dataPtr;
};

}//otus
