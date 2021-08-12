#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    T* arr;
    int size;
public:
    Vector() = default;
    Vector(unsigned int size);
    ~Vector();
    int length();
    void push_back(T element);
    T& operator[] (int index) const;
};

template <typename T>
Vector<T>::Vector(unsigned int size) : size(size)
{
    this->arr = new T[size];
}

template <typename T>
Vector<T>::~Vector<T>()
{
    delete arr;
    this->size = 0;
}

template <typename T>
int Vector<T>::length()
{
    return this->size;
}

template<typename T>
void Vector<T>::push_back(T element)
{
    this->arr[this->size] = element;
    this->size++;
}

template <typename T>
T& Vector<T>::operator[] (int index) const
{
    if (index >= this->size)
        throw std::out_of_range("Out of range!");
    return arr[index];
}

#endif //VECTOR_H
