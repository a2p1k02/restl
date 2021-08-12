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
    this->length = strlen(data);
}

void astr_free(astr* str)
{
    if (str->data != NULL)
        delete str->data;
    str->data = nullptr;
    str->length = 0;
}

size_t astr_len(astr* str)
{
    return strlen(str->data);
}

astr astr::operator= (const char* str_data)
        {
    astr_init(str_data);
    return str_data;
}

astr astr::operator+ (const astr str1)
{
    astr finalstr;

    finalstr.length = this->length + str1.length;
    finalstr.data = new char[finalstr.length + 1];

    strncat(finalstr.data, this->data, this->length);
    strncat(finalstr.data, str1.data, finalstr.length);

    return finalstr;
}

astr astr::operator* (const int number)
{
    astr finalstr;

    finalstr.data = new char[this->length];
    finalstr.length = this->length * number;

    for (int i = 1; i <= number; i++)
        strncat(finalstr.data, this->data, finalstr.length);

    return finalstr;
}

std::ostream& operator<< (std::ostream& cout, const astr str)
{
    cout << str.data;
    return cout;
}
