#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned long size_t;

template <typename T>
class Vector {
    T* arr; // Vector
    size_t size; // capacity of Vector
    size_t capacity; // count of elements
public:
    Vector(); //Default constructor
    Vector(size_t size); // Init constructor
    Vector(Vector<T>& vector); // Copy constructor;
    Vector(Vector<T>&& vector); // Move constructor;
    ~Vector(); // Destructor;

    size_t length();
    void push_back(const T& value);
    void pop_back();
    T& at(size_t index);

    T& operator[] (size_t index);
};

template<typename T>
Vector<T>::Vector()
{
    this->arr = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template<typename T>
Vector<T>::Vector(size_t size) : size(size), capacity(0)
{
    this->arr = new T[size];
}

template<typename T>
Vector<T>::Vector(Vector<T>& vector) : size(vector.size), capacity(vector.capacity)
{
    this->arr = new T[size];
    this->arr = vector.arr;
}

template<typename T>
Vector<T>::Vector(Vector<T>&& vector) : size(vector.size), capacity(vector.capacity)
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
size_t Vector<T>::length()
{
    return this->size;
}

template<typename T>
T& Vector<T>::at(size_t index)
{
    if (index >= this->size)
        throw std::out_of_range("Out of range!");
    return this->arr[index];
}

template<typename T>
void Vector<T>::pop_back()
{
    if (size == 0)
        return;
    this->size--;
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index >= this->size)
        throw std::out_of_range("Out of range!");
    return this->arr[index];
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    if (this->capacity == 0) {
        this->arr = new T[sizeof(T)*2];
        this->capacity = 2;
    }
    this->arr[this->size] = value;
    this->size++;
}

#endif //VECTOR_H