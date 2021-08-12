#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    T* arr;
    std::size_t capacity;
public:
    Vector() = default;
    Vector(unsigned int size);
    ~Vector();
    std::size_t size();
    void push_back(T element);
    T& operator[] (int index) const;
};

template <typename T>
Vector<T>::Vector(unsigned int size) : capacity(size)
{
    this->arr = new T[size];
}

template <typename T>
Vector<T>::~Vector<T>()
{
    delete[] arr;
    arr = nullptr;
    this->capacity = 0;
}

template <typename T>
std::size_t Vector<T>::size()
{
    return this->capacity;
}

template<typename T>
void Vector<T>::push_back(T element)
{
    this->arr[this->capacity] = element;
    this->capacity++;
}

template <typename T>
T& Vector<T>::operator[] (int index) const
{
    if (index >= this->capacity)
        throw std::out_of_range("Out of range!");
    return arr[index];
}

#endif //VECTOR_H
