#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <initializer_list>
#include <cstring>
#include <ostream>

namespace restl {

    template <typename T>
    class Vector {
        T* arr; // Vector
        std::size_t length; // capacity of Vector
        std::size_t capacity; // count of elements
    public:
        //Init methods
        Vector(); //Default constructor
        Vector(std::size_t size); // Init constructor
        Vector(Vector<T>& vector); // Copy constructor;
        Vector(Vector<T>&& vector); // Move constructor;
        ~Vector(); // Destructor;

        //Vector methods
        std::size_t size();
        void push_back(const T& value);
        void pop_back();
        void reserve(const std::size_t& size);
        T& at(std::size_t index);

        //Operators
        T& operator[] (std::size_t index);
        //Vector<T> operator= (std::initializer_list<T> list);
        Vector<T>& operator= (const Vector<T>& vector);
    };

    template<typename T>
    Vector<T>::Vector()
    {
        this->arr = nullptr;
        this->length = 0;
        this->capacity = 0;
    }

    template<typename T>
    Vector<T>::Vector(std::size_t size) : length(size), capacity(0)
    {
        this->arr = new T[size];
    }

    template<typename T>
    Vector<T>::Vector(Vector<T>& vector) : length(vector.length), capacity(vector.capacity)
    {
        this->arr = new T[vector.length];
        memmove(this->arr, vector.arr, sizeof(T) * this->length);
    }

    template<typename T>
    Vector<T>::Vector(Vector<T>&& vector) : length(vector.length), capacity(vector.capacity)
    {
        this->arr = vector.arr;
        vector.arr = nullptr;
    }

    template<typename T>
    Vector<T>::~Vector<T>()
    {
        delete[] this->arr;
        arr = nullptr;
    }

    template<typename T>
    std::size_t Vector<T>::size()
    {
        return this->length;
    }

    template<typename T>
    T& Vector<T>::at(std::size_t index)
    {
        if (index >= this->length)
            throw std::out_of_range("Out of range!");
        return this->arr[index];
    }

    template<typename T>
    void Vector<T>::pop_back()
    {
        if (this->length == 0)
            return;
        this->length--;
    }

    template<typename T>
    void Vector<T>::reserve(const std::size_t& size)
    {
        if (size == 0)
            return;
        this->length = size;
        T* temp = new T[size];

        memmove(temp, this->arr, sizeof(T) * this->capacity);

        delete this->arr;
        this->arr = temp;
    }

    template<typename T>
    void Vector<T>::push_back(const T& value)
    {
        if (this->capacity == this->length)
            reserve(this->length * 2);
        this->arr[this->capacity++] = value;
    }

    template<typename T>
    T& Vector<T>::operator[](std::size_t index)
    {
        if (index >= this->length)
            throw std::out_of_range("Out of range!");
        return this->arr[index];
    }

//    template<typename T>
//    Vector<T> Vector<T>::operator= (std::initializer_list<T> list)
//    {
//        for (std::size_t i = 0; i < list.size(); i++)
//            this->push_back(list[i]);
//        return *this;
//    }

    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& vector)
    {
        this->capacity = vector.capacity;
        this->length = vector.length;
        this->arr = new T[vector.length];
        memmove(this->arr, vector.arr, sizeof(T) * this->length);

        return *this;
    }

} //end namespace

#endif //VECTOR_H
