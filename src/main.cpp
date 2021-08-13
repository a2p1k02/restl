#include "restl/astring.hpp"
#include "restl/vector.hpp"
#include <vector>
#include <iostream>

void astring_test()
{
    //restl::Astring str1("Hello, ");
    restl::Astring str1 = "Hello, ";
    //restl::Astring str2("World!");
    restl::Astring str2 = "World!";
    restl::Astring str3 = str1 + str2;

    std::cout << str3 << std::endl;

    restl::Astring str4("test");
    
    std::cout << str4 * 2 << std::endl;
}

void vector_test()
{
    restl::Vector<int> v(1);
    v[0] = 10;
    v.push_back(20);
    v.push_back(30);

    for (auto i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

int main()
{
    //astring_test();

    //std::cout << std::endl;

    vector_test();

    std::cout << std::endl;

    std::vector<int> v(1);
    v[0] = 10;
    v.push_back(20);
    v.push_back(30);

    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
