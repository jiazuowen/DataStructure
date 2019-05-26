/**
 * 数据结构  列表 (使用C++模板类实现，需要C++11标准)
 * 使用顺序存储的方式
 * Author Jack
 * Date 2019-04-24
*/
#ifndef _JAC_LIST_H
#define _JAC_LIST_H

#include <functional>
using namespace std;

namespace Jac
{

#define LIST_INIT_LENGTH    50
#define LIST_INCREACE       10

template<typename T>
class JacList 
{
    T* head;
    T* tail;
    int listSize;
public:
    JacList();
    ~JacList();
    void Clear();
    int Length() const;
    bool Empty() const;
    bool Insert(int index, T const &t);
    void RemoveAt(int i);
    void Append(T const &t);
    void Traverse(std::function<void(T)> visit) const;
    T& operator[](int i);
private:
    void initList(int l);
    void expendList();
};

template<typename T>
JacList<T>::JacList()
{
    initList(LIST_INIT_LENGTH);
}

template<typename T>
void JacList<T>::initList(int l)
{
    head = new T[l];
    tail = head;
    listSize = l;
}

template<typename T>
void JacList<T>::expendList()
{
    T* newHead = new T[listSize + LIST_INCREACE];
    T* newp = newHead;
    T* p = head;
    while (p != tail)
    {
        *newp++ = *p++;
    }
    delete [] head;
    head = newHead;
    tail = head + listSize;
    listSize += LIST_INCREACE;
}

template<typename T>
JacList<T>::~JacList()
{
    delete [] head;
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template<typename T>
void JacList<T>::Clear()
{
    tail = head;
}

template<typename T>
int JacList<T>::Length() const
{
    return tail - head;
}

template<typename T>
bool JacList<T>::Empty() const
{
    return tail == head;
}

template<typename T>
bool JacList<T>::Insert(int i, T const &t)
{
    if (i >= Length()) return false;     
    if (Length() >= listSize) expendList();    
    T* ip = head + i;
    T* tp = tail;
    while (tp != ip)
    {
        *tp = *(tp - 1);
        tp--;
    }
    *ip = t;
    tail++;
    return true;
}

template<typename T>
void JacList<T>::RemoveAt(int i)
{
    if (i > Length()) return;     
    T* p = head + i;
    while (p != (tail - 2))
    {
        *p = *(p + 1);
        p++;
    }
    tail--;
}

template<typename T>
void JacList<T>::Append(T const &t)
{
    if (Length() >= listSize) expendList();    
    *tail = t;
    tail++;
}

template<typename T>
void JacList<T>::Traverse(std::function<void(T)> visit) const
{
    T* p = head;
    while (p != tail)
    {
        visit(*p++);
    }
}

template<typename T>
T& JacList<T>::operator[](int i)
{
    if (i >= Length())
        throw "index vaild";
    return *(head + i);
}

}

#endif // !_JAC_LIST_H