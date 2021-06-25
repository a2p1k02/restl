#include "restl/astring.h"
#include "restl/new.hpp"
#include <iostream>

void astring_test() {
    astr str1 = "Hello, ";
    astr str2 = "World!";
    astr str3 = str1 + str2;

    astr string1 = "1";
    astr string2 = string1 * 2;

    std::cout << str3 << std::endl;
    std::cout << string2 << std::endl;
}

int main() {
    
    astr* str1 = new astr;

    return 0;
}
