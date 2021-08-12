#include "astring.h"
#include <cstring>

astr::astr() = default;

astr::astr(const char *data)
{
    astr_init(data);
}

void astr::astr_init(const char* data)
{
    this->data = (char*) data;
    this->capacity = strlen(data);
}

std::size_t astr::length()
{
    return this->capacity;
}

astr astr::operator= (const char* str_data)
{
    astr_init(str_data);
    return str_data;
}

astr astr::operator+ (const astr str1)
{
    astr finalstr;

    finalstr.capacity = this->capacity + str1.capacity;
    finalstr.data = new char[finalstr.capacity + 1];

    strncat(finalstr.data, this->data, this->capacity);
    strncat(finalstr.data, str1.data, finalstr.capacity);

    return finalstr;
}

astr astr::operator* (const int number)
{
    astr finalstr;

    finalstr.data = new char[this->capacity];
    finalstr.capacity = this->capacity * number;

    for (int i = 1; i <= number; i++)
        strncat(finalstr.data, this->data, finalstr.capacity);

    return finalstr;
}

std::ostream& operator<< (std::ostream& cout, const astr str)
{
    cout << str.data;
    return cout;
}
