#include "astring.h"
#include <cstring>

astr::astr() = default;

astr::astr(const char *data) {
    astr_init(data);
}

void astr::astr_init(const char* data) {
    this->data = (char*) data;
    this->length = strlen(data);
}

void astr_free(astr* str) {
    if (str->data != NULL)
        delete str->data;
    str->data = nullptr;
    str->length = 0;
}

size_t astr_len(astr* str) {
    return strlen(str->data);
}

astr astr::operator= (const char* str_data) {
    astr_init(str_data);
    return str_data;
}

astr astr::operator+(const astr str1) {
    astr catstr;
    size_t catsize = catstr.length + 1;

    catstr.length = this->length + str1.length;
    catstr.data = new char[catstr.length + 1];
    strncpy_s(catstr.data, catsize, this->data, this->length);
    strncpy_s(catstr.data + catsize, str1.length + 1, str1.data, str1.length);

    return catstr;
}

std::ostream& operator<< (std::ostream& cout, const astr str) {
    cout << str.data;
    return cout;
}
