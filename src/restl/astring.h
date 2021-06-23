#ifndef ASTRING_H_
#define ASTRING_H_

#include <cstring>
#include <ostream>

class astr {
private:
    char* data = nullptr;
    size_t length = 0;
    void astr_init(const char* data);
public:
    astr();
    astr(const char* data);
    friend std::ostream& operator<< (std::ostream& cout, const astr str);
    astr operator= (const char* str_data);
    astr operator+ (const astr str1);
    friend void astr_free(astr* str);
    friend size_t astr_len(astr* str);
};

#endif //ASTRING_H_
