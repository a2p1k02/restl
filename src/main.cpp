#include "restl/astring.h"
#include "restl/new.h"
#include "restl/vector.h"
#include <iostream>

void astring_test() {
    astr str1 = "Hello, ";
    astr str2 = "World!";
    astr str3 = str1 + str2;
    std::cout << str3 << std::endl;
}

int main() {
    
    astr* str1;

    return 0;
}
