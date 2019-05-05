/**
 * 字符串结构
 * Author Jack
 * Date 2019-05-01
*/
#include "JacString.h"

JacString::JacString(int size)
{
    initString(nullptr, size);
}

JacString::JacString(const char* str)
{
    int i = 0;
    const char* c = str;
    for (i = 0, c = str; *c; ++i, ++c);
    initString(str, i);
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
    int initSize = STRING_INIT_SIZE > len ? STRING_INIT_SIZE : len;
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

int JacString::Index(int pos, const char* str) const /* 还需改良, 可以使用KMP算法*/
{
    int i = pos, j = 0;
    while (*(str + j) && *(this->base + i))
    {
       if (*(this->base + i) == *(str + j)) { ++i; ++j; }
       else { i = i - j + 1; j = 0; }
    }

    if (j > 0) return i - j;
    return -1;
}

void JacString::Replace(const char* old, const char* nnw)
{
    int oldLen;
    int nnwLen;
    for (oldLen = 0; *(old + oldLen); ++oldLen);
    for (nnwLen = 0; *(nnw + nnwLen); ++nnwLen);
    int pos = Index(0, old);
    while (pos >= 0) {
        Delete(pos, oldLen);
        Insert(pos, nnw);
        if (pos + nnwLen > this->length) break;
        pos = Index(pos + nnwLen, old);
    }
}

bool JacString::Insert(int pos, const char* str)
{
    if (pos < 0 || pos > this->length) return false;
    int i = 0;
    for (; *(str + i); ++i);
    if (this->length + i > this->size) {
        expendString(this->length + i - this->size);
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
    int i = 0;
    const char* p = str;
    for (; *p; ++i, ++p);
    if (i > this->size) {
        expendString(i - this->size);
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
    if (a.Length() + b.Length() > a.size) {
        int increase = a.Length() + b.Length() - a.size;
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