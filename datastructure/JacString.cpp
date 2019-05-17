/**
 * 字符串结构
 * Author Jack
 * Date 2019-05-01
*/
#include "JacString.h"
#include "mathf.h"

JacString::JacString(int size)
{
    initString(nullptr, size);
}

JacString::JacString(const char* str)
{
    int len = strlen(str);
    initString(str, len);
}

JacString::JacString(const JacString &jstr)
{
    initString(jstr.base, jstr.Length());
}

JacString::~JacString()
{
    delete [] this->base;
    this->length = 0;
    this->size = 0;
    this->base = nullptr;
}

void JacString::initString(const char* str, int len)
{
    int initSize = (STRING_INIT_SIZE > len ? STRING_INIT_SIZE : len) + MORE_SIZE;
    this->base = new char[initSize];
    this->size = initSize;
    if (str != nullptr) {
        int i = 0;
        for (const char* c = str; *c && (i < len); ++i, ++c) {
            *(this->base + i) = *c;
        }
        *(this->base + i) = '\0';
        this->length = i;
    } else {
        *this->base = '\0';
        this->length = 0;
    }
}

void JacString::expendString(int increase)
{
    if (increase < STRING_INCREASE) increase = STRING_INCREASE;

    char* newbase = new char[this->size + increase];
    char* p = this->base;
    int i = 0;
    for (; *p; ++i, ++p) {
        *(newbase+i) = *p;
    }
    *(newbase+i) = '\0';
    delete [] this->base;
    this->base = newbase;
    this->length = i;
    this->size += increase;
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
    int i = strlen(str);
    int count = this->length < i ? this->length : i;
    for (i = 0; i < count; ++i) {
        if (*(this->base + i) < *(str + i)) {
            res = -1;
            break;
        } else if (*(this->base + i) > *(str + i)) {
            res = 1;
            break;
        }
    }
    return res;
}

JacString JacString::SubString(int pos, int len) const
{
    JacString str;

    if (pos < this->length) {
        const char* p = (this->base + pos);
        int i = 0;
        if (len > str.Length()) {
            str.expendString(len - str.Length());
        }
        for (i = 0; *p && i < len; ++p, ++i) {
            *(str.base + i) = *p;
        }
        *(str.base + i) = '\0';
        str.length = i;
        return str;
    }
    return str;
}

int JacString::Index(int pos, const char* str) const /* 使用KMP算法*/
{
    if (pos >= this->Length()) return -1;

    int len;
    int k = pos;
    int j = 0;
    int res = -1;
    
    int*next = getNextKMP(str, len);
    while (*(this->base + k) != '\0' && j < len)
    {
        if ((j == -1) || (*(this->base + k) == *(str + j))) {
            if (j == -1) {
                ++k;
                j = 0;
            } else {
                ++k;
                ++j; 
            }
        } else { 
            j = *(next + j);
        }
    }
    delete [] next;
    next = 0;

    if (j >= len) {
        res = k - len;
    }
    return res;
}

void JacString::Replace(const char* old, const char* nnw)
{
    int oldLen = strlen(old);
    int nnwLen = strlen(nnw);
    int pos = Index(0, old);
    while (pos >= 0) {
        Delete(pos, oldLen);
        Insert(pos, nnw);
        pos += nnwLen;
        pos = Index(pos, old);
    }
}

bool JacString::Insert(int pos, const char* str)
{
    if (pos < 0 || pos > this->length) return false;
    int i = strlen(str);
    if (this->length + i > this->Size()) {
        expendString(this->length + i - this->Size());
    }
    char* tail = this->base + this->length + i;
    const char* head = this->base + this->length;
    char* p = this->base + pos;
    *tail = '\0';
    this->length += i;
    while (head != p)
    {
        *--tail = *--head;
    }
    head = str;
    while (p != tail)
    {
        *p++ = *head++;
    }
    return true;
}

void JacString::Delete(int pos, int len)
{
    if (pos < 0 || len <= 0) return;
    if (pos + len > this->length)
       throw "JacString::Delete Out of Range";
    char* head = this->base + pos;
    const char* tail = this->base + pos + len;
    while (*tail) {
        *head++ = *tail++;
    }
    *head = '\0';
    this->length -= len;
}

void JacString::operator=(const char* str)
{
    int i = strlen(str);
    if (i > this->Size()) {
        expendString(i - this->Size());
    }
    for (i = 0; *(str + i); ++i) {
        *(this->base + i) = *(str + i);
    }
    *(this->base + i) = '\0';
    this->length = i;
}

JacString JacString::operator+(const JacString &b)
{
    JacString a;
    a = *this;
    if (a.Length() + b.Length() > a.Size()) {
        int increase = a.Length() + b.Length() - a.Size();
        if (increase < STRING_INCREASE) increase = STRING_INCREASE;
        a.expendString(increase);
    }
    const char* p = b.base;
    char* ap = a.base + a.Length();
    int i = 0;
    for (; *p; ++i, ++p, ++ap) {
        *ap = *p;
    }
    *ap = '\0';
    a.length = a.Length() + i;
    return a;
}

bool JacString::operator==(const char* str) const
{
    bool res = false;
    const char* p = this->base;
    int i = 0;
    while (*p && *(str + i))
    {
        if (*p++ != *(str + i++))
            break;
    }
    if (i == this->length && !*(str+i)) res = true;
    return res;
}

int* JacString::getNextKMP(const char* str, int & len) const
{
    len = strlen(str);
    if (len == 0) return 0;

    int* next = new int[len];
    *next = -1;
    int i = 1;
    while (i < len)
    {
        *(next + i) = mathf::abcwabc(str, i);
        ++i;
    }

    return next;
}

int JacString::strlen(const char* str) const
{
    int len;
    for (len = 0; *(str + len); ++len);
    return len;
}
