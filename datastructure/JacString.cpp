/**
 * 字符串结构
 * Author Jack
 * Date 2019-05-01
*/
#include "JacString.h"

JacString::JacString()
{
    initString(STRING_INIT_SIZE);
}

JacString::JacString(const char* str, int len)
{
    int i = 0;
    const char* c = str;
    if (len > 0)
        for (i = 0, c = str; *c && i < len; ++i, ++c);
    else
        for (i = 0, c = str; *c; ++i, ++c);
    initString(STRING_INIT_SIZE > i ? STRING_INIT_SIZE : i, str);
}

JacString::JacString(const JacString &jstr)
{
    initString(STRING_INIT_SIZE > jstr.Length() ? STRING_INIT_SIZE : jstr.Length(), jstr.base);
}

JacString::~JacString()
{
    delete [] this->base;
    this->length = 0;
    this->size = 0;
    this->base = nullptr;
}

void JacString::initString(const int &size, const char* str)
{
    this->base = new char[size];
    this->length = 0;
    this->size = size;
    if (str != nullptr) {
        int i = 0;
        for (const char* c = str; *c; ++i, ++c) {
            *(base + i) = *c;
        }
        *(base + i) = '\0';
        this->length = i;
    }
}

void JacString::expendString(int increase)
{
    char* newbase = new char[size + increase];
    char* p = base;
    int i = 0;
    for (i = 0, p = base; *p; ++i, ++p) {
        *(newbase+i) = *p;
    }
    *(newbase+i) = '\0';
    delete [] base;
    base = newbase;
    length = i;
    size += increase;
}

int JacString::Length() const
{
    return length;
}

void JacString::Clear()
{
    *base = '\0';
    length = 0;
}

bool JacString::Empty() const 
{
    return length == 0 || *base == '\0';
}

int JacString::Compare(const char* str) const
{
    int res = 0;
    int i = 0;
    for (i = 0; *(str +i); ++i);
    int count = length < i ? length : i;
    for (i = 0; i < count; ++i) {
        if (*(base + i) < *(str + i)) {
            res = -1;
            break;
        } else if (*(base + i) > *(str + i)) {
            res = 1;
            break;
        }
    }
    return res;
}

JacString JacString::SubString(int pos, int len) const
{
    if (pos < this->length) {
        const char* p = (this->base + pos);
        JacString str = JacString(p, len);
        return str;
    }
    return JacString();
}

int JacString::Index(const char* str) const
{
    int i = 0, j = 0;
    while (*(str + j) && *(base + i))
    {
       if (*(base + i) == *(str + j)) { ++i; ++j; }
       else { i = i - j + 2; j = 0; }
    }

    if (j > 0) return i - j;
    return -1;
}

void JacString::Replace(const char* old, const char* nnw)
{
    
}

bool JacString::Insert(int pos, const char* str)
{
    return false;
}

void JacString::Delete(int pos, int len)
{
    *(base + pos) = '\0';
    length = pos;
}

void JacString::operator=(const char* str)
{
    int i = 0;
    const char* p = str;
    for (; *p; ++i, ++p);
    if (i > this->size) {
        int increase = i - this->size;
        if (increase < STRING_INCREASE) increase = STRING_INCREASE;
        expendString(increase);
    }
    for (i = 0, p = str; *p; ++i, ++p) {
        *(this->base + i) = *p;
    }
    *(this->base + i) = '\0';
    this->length = i;
}

JacString JacString::operator+(const JacString &b)
{
    JacString a;
    a = *this;
    if (a.length + b.length > a.size) {
        int increase = a.length + b.length - a.size;
        if (increase < STRING_INCREASE) increase = STRING_INCREASE;
        a.expendString(increase);
    }
    const char* p = b.base;
    char* ap = a.base + a.length;
    int i = 0;
    for (; *p; ++i, ++p, ++ap) {
        *ap = *p;
    }
    *ap = '\0';
    a.length = a.length + i;
    return a;
}

bool JacString::operator==(const char* str) const
{
    return false;
}