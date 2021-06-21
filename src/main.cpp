#include "restl/astring.h"
#include <iostream>

int main() {
    
    astr str1 = "Hello, ";
    astr str2 = "World!";
    astr str3 = str1 + str2;

    std::cout << str3 << std::endl;

    return 0;
}
