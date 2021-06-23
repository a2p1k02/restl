#include "new.h"

inline void* operator new(size_t, void* ptr) {
    return ptr;
}
