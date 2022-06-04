#pragma once

#include <stddef.h>
#include <cstring>
#include <memory>

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
    explicit vector( int capacity = 3 ): capacity_( capacity ), size_ (0 )
    {
        data_ptr_ = std::make_unique<T[]>(capacity_);
    }
    
    /// @todo из условия задачи не понял нужен ли конструтор копирования или нет
    /// пока что удалил его
    vector( const vector& other ) = delete;
    vector& operator = ( const vector& other )  = delete;
   
    /// @brief возвращаем элемент по индексу
    const T& operator[]( int index ) const
    {
        return data_ptr_[index];
    }
    
    /// @brief освобожваем ресурс,  в данном случае память
    ~vector()
    {
        data_ptr_.reset();
    }
    
    /// @brief отображаем данные
    void print()
    {
        for( size_t counter = 0; counter <size_; counter++ )
        {
            std::cout<<data_ptr_[counter]<<std::endl;
        }
    }
    
    /// @brief вставляем элемент в конец
    void push_back( const T& data )
    {
        if( size_ > capacity_ )
        {
            capacity_ *=2;
            reserve(capacity_ + 1);
        }
        
        data_ptr_[size_++] = data;
    }
    
    /// @brief удаляем элемент с конца
    void pop_back()
    {
        /// @todo для освобождения данных вызываю конструтор по умолчанию далее уменьшаем индекс
        /// не уверен, что это хорошая мысль но других идей нет
        data_ptr_[size_ -1 ] = T();
        size_--;
    }
    
    /// @brief вставляем данные по определенному индексу
    void insert( int index, const T& data )
    {
        if( index > capacity_ )
        {
            reserve(index + 1);
            size_ = index + 1;
            
        }
        
        size_t tmp_size = size_ + 1;
        // чтобы не усложнять код не стал делать обработку исключений на случай не сли удалось выделить память
        auto tmp_ptr = std::make_unique<int[]>(tmp_size);
        memset( tmp_ptr.get(), 0, tmp_size * sizeof( int ) );
        size_t counter = 0;
        size_t i = 0;
        // через два цикла выполняем вставку элемента в указанную позицию
        for( ; counter <= index ; counter++, i++)
        {
            tmp_ptr[counter] = data_ptr_[counter];
            if( counter == index )
            {
                tmp_ptr[index ] = data;
                break;
            }
        }
        
        counter++;
        for( ; counter <= size_; counter++, i++ )
        {
            tmp_ptr[counter] = data_ptr_[i];
        }
        
        size_ = counter;
        data_ptr_ = std::move(tmp_ptr);
}

private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr<T[]>data_ptr_;
    
    /// @brief резервируем новую память
    void reserve( size_t size )
    {
        if(size < capacity_)
        {
            return;
        }
        
        T* tmp = data_ptr_.get();
        data_ptr_ = std::make_unique<T[]>(size);
        for( size_t counter = 0; counter < size; counter++ )
        {
            data_ptr_[counter] = tmp[counter];
            memset(data_ptr_.get() + size_, 0, size*sizeof(int) );
        }
    }
};

}//otus
