/**
 * 字符串结构
 * Author Jack
 * Date 2019-04-27
*/
#ifndef _JAC_STRING_H
#define _JAC_STRING_H

#include <iostream>

#define STRING_INIT_SIZE 100
#define STRING_INCREASE 20

class JacString
{
    char* base;
    int length;
    int size;
public:
    JacString();
    JacString(const char* str, int len = 0);
    JacString(const JacString &jstr);
    ~JacString();

    int Length() const;
    void Clear();
    bool Empty() const;
    int Compare(const JacString & js) const { return Compare(js.base); };
    int Compare(const char* str) const;
    JacString SubString(int pos, int len) const;
    int Index(const JacString &a) const { return Index(a.base); };
    int Index(const char* str) const;
    void Replace(const JacString &old, const JacString &nnw) { Replace(old.base, nnw.base); };
    void Replace(const char* old, const char* nnw);
    bool Insert(int pos, const JacString &js) { return Insert(pos, js.base); };
    bool Insert(int pos, const char* str);
    void Delete(int pos, int len);
    void operator=(const JacString &js) { *this = js.base; };
    void operator=(const char* str);
    JacString operator+(const JacString &b);
    bool operator==(const JacString &b) const { return *this == b.base; };
    bool operator==(const char* str) const;
    bool operator!=(const JacString &b) { return !(*this == b); }
    bool operator!=(const char* str) { return !(*this == str); }
    friend std::ostream &operator<<(std::ostream &output, const JacString &d) { output << d.base; return output; }
private:
    void initString(const int &size, const char* str = nullptr);
    void expendString(int increase);
    
};

#endif // !_JAC_STRING_H
