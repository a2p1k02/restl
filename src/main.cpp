#include "restl/astring.h"
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
    
    astring_test();

    return 0;
}
