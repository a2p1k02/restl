#ifndef ASTRING_H_
#define ASTRING_H_

#include <cstring>
#include <ostream>

class astr {
private:
    char* data = nullptr;
    size_t capacity = 0;
    void astr_init(const char* data);
public:
    astr();
    astr(const char* data);
    friend std::ostream& operator<< (std::ostream& cout, const astr str);
    astr operator= (const char* str_data);
    astr operator+ (const astr str1);
    astr operator* (const int number);
    std::size_t length();
};

#endif //ASTRING_H_
