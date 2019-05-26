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

template<typename T>
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

template<typename T>
JacArray<T>::JacArray(int size)
{
    base = new T[size];
    length = size;
}

template<typename T>
JacArray<T>::~JacArray()
{
    delete [] base;
    length = 0;
}

template<typename T>
int JacArray<T>::Length() const
{
    return length;
}

template<typename T>
T& JacArray<T>::operator[](int i)
{
    if (i >= length)
        throw "JacArray out of bounds";
    return *(base + i);
}

}

#endif // !_JAC_ARRAY_H