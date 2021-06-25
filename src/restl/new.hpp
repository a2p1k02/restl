#ifndef NEW_H_
#define NEW_H_

inline void* operator new(unsigned int, void* ptr) {
    return ptr;
}

#endif //NEW_H_
