#include <cstddef>

#ifndef NEW_H_
#define NEW_H_

inline void* operator new(size_t, void* ptr) {
    return ptr;
}

#endif //NEW_H_
