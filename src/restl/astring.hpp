#ifndef ASTRING_H
#define ASTRING_H

#include <cstdlib>
#include <cstring>
#include <ostream>
#include <stdexcept>

namespace restl {
    class Astring {
        char* data;
        std::size_t length;

        Astring create(const char* data);
    public:
        Astring();
        Astring(const char* str);
        Astring(const Astring& str);
        Astring(Astring&& str);

        std::size_t size();
        Astring operator= (const char* data);
        Astring operator= (const Astring& str);
        Astring operator+ (const Astring str);
        Astring operator* (const std::size_t number);

        friend std::ostream& operator<< (std::ostream& cout, Astring str);
    };

    Astring::Astring()
    {
        this->data = nullptr;
        this->length = 0;
    }

    Astring::Astring(const char* str)
    {
        this->data = (char*)str;
        this->length = strnlen(str, 1024);
    }

    Astring::Astring(const Astring& str)
    {
        this->data = str.data;
        this->length = str.length;
    }

    Astring::Astring(Astring&& str)
    {
        this->data = str.data;
        this->length = str.length;

        delete [] str.data;
        str.data = nullptr;
        str.length = 0;
    }

    std::size_t Astring::size()
    {
        return this->length;
    }

    Astring Astring::create(const char* data)
    {
        Astring string;

        if (string.data != nullptr) {
            delete string.data;
            string.data = nullptr;
            string.length = 0;
        }
        
        string.data = static_cast<char*>(malloc(sizeof(char) * strlen(data)));
        string.length = strlen(data);

        strncat(string.data, data, string.length);

        return string;
    }

    Astring Astring::operator= (const char* str)
    {
        create(str);
        return (Astring)str;
    }

    Astring Astring::operator= (const Astring& str)
    {
        this->data = str.data;
        this->length = str.length;
        return *this;
    }

    Astring Astring::operator+ (const Astring str)
    {
        Astring finalstr;

        finalstr.length = str.length;
        finalstr.data = new char[finalstr.length+1];

        strncat(finalstr.data, this->data, this->length);
        strncat(finalstr.data, str.data, finalstr.length);

        return finalstr;
    }

    Astring Astring::operator* (const std::size_t number)
    {
        Astring str;

        str.length = this->length * number;
        str.data = new char[this->length * number];

        for (std::size_t i = 0; i < number; i++)
            strncat(str.data, this->data, str.length);

        return str;
    }

    std::ostream& operator<< (std::ostream& cout, Astring str)
    {
        cout << str.data;
        return cout;
    }
}

#endif //ASTRING_H