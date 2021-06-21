#include "astring.h"

astr::astr() = default;

astr::astr(const char *data) {
    astr_init(data);
}

void astr::astr_init(const char *data) {
    this->data = (char*) data;
    this->length = strlen(data);
}

void astr_free(astr *str) {
    if (str->data != NULL)
        delete str->data;
    str->data = nullptr;
    str->length = 0;
}

size_t astr_len(astr* str) {
    return strlen(str->data);
}

astr astr::operator= (const char *str_data) {
    astr_init(str_data);
    return str_data;
}

std::ostream& operator<< (std::ostream& cout, const astr str) {
    cout << str.data;
    return cout;
}
