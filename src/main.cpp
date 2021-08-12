#include "restl/astring.hpp"
#include "restl/vector.hpp"
#include <iostream>

void astring_test()
{
    restl::astr str1 = "Hello, ";
    restl::astr str2 = "World!";
    restl::astr str3 = str1 + str2;

    restl::astr str4 = "test";
    restl::astr str5 = str4 * 2;

    std::cout << str3 << std::endl;
    std::cout << str5 << std::endl;

    std::cout << str3.size() << std::endl;
}

void vector_test()
{
    restl::Vector<int> v(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.length(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::cout << v.length() << std::endl;

    v.at(v.length()-1) = 10;

    for (int i = 0; i < v.length(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    v.pop_back();

    for (int i = 0; i < v.length(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

int main()
{
    astring_test();

    std::cout << std::endl;

    vector_test();

    return 0;
}
