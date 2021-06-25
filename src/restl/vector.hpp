#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T> class vector {
private:
    T* arr;
    int length;
public:
    vector() = default;
    vector(T something) {

    }
    ~vector() {
        delete arr;
    }
    int getLength() {
        return this->length;
    }
    vector operator= (const vector* vec1) {

    }
};

#endif //VECTOR_H_
