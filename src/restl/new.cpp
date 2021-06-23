#include "new.h"
#include "new.h"

void* operator new(size_t, void* ptr) {
    return ptr;
}
