#include "restl/astring.h"
#include "restl/vector.hpp"
#include <iostream>

void astring_test()
{
    astr str1 = "Hello, ";
    astr str2 = "World!";
    astr str3 = str1 + str2;

    astr str4 = "test";
    astr str5 = str4 * 2;

    std::cout << str3 << std::endl;
    std::cout << str5 << std::endl;

    std::cout << str3.length() << std::endl;

}

void vector_test()
{
    Vector<int> v;
    v.push_back(10);

    for (int i = 0; i < v.length(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::cout << v.length() << std::endl;
}

int main()
{
    //astring_test();

    vector_test();

    return 0;
}
