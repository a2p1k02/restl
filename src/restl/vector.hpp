#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T> class vector {
private:
    T* arr;
    int length;
public:
    vector(T something);
    ~vector();
    int getLength();
    vector operator= (const vector* vec1);
};

#endif //VECTOR_H_
