/**
 * 一维数组结构
 * Author Jack
 * Date 2019-04-25
*/
#ifndef _JAC_ARRAY_H
#define _JAC_ARRAY_H

#include <functional>
using namespace std;

namespace Jac
{

template<class T>
class JacArray
{
    T* base;
    int length;
public:
    JacArray(int size);
    ~JacArray();
    int Length() const;
    T& operator[](int i);
};

template<class T>
JacArray<T>::JacArray(int size)
{
    base = new T[size];
    length = size;
}

template<class T>
JacArray<T>::~JacArray()
{
    delete [] base;
    length = 0;
}

template<class T>
int JacArray<T>::Length() const
{
    return length;
}

template<class T>
T& JacArray<T>::operator[](int i)
{
    if (i >= length)
        throw "JacArray out of bounds";
    return *(base + i);
}

}

#endif // !_JAC_ARRAY_H