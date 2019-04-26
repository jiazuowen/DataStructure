/**
 * 数据结构  栈 (使用C++模板类实现，需要C++11标准)
 * Author   Jack
 * Date     2019-04-24
 */
#ifndef _JAC_STACK_H
#define _JAC_STACK_H

#include <functional>

using namespace std;

namespace Jac
{

#define STACK_INIT_SIZE 100
#define STACK_INCREASESIZE 10

template<class T>
class JacStack {
    T*  base;
    T*  top;
    int stacksize;
public:
    JacStack();
    JacStack(int initSize);
    ~JacStack();

    void Clear();
    int Length() const;
    bool Empty() const;
    bool GetTop(T &t) const;
    void Push(T const &t);
    bool Pop(T &t);
    void Traverse(std::function<void(T)> visit) const;
private:
    void initStack(int initsize);
    void expendStack();
};

template<class T>
JacStack<T>::JacStack()
{
    initStack(STACK_INIT_SIZE);
}

template<class T>
JacStack<T>::JacStack(int initsize)
{
    initStack(initsize);
}

template<class T>
JacStack<T>::~JacStack()
{
    delete [] base;
    base = nullptr;
    top = nullptr;
    stacksize = 0;
}

template<class T>
void JacStack<T>::Clear()
{
    top = base;
}

template<class T>
int JacStack<T>::Length() const
{
    return stacksize;
}

template<class T>
bool JacStack<T>::Empty() const
{
    return top == base;
}

template<class T>
bool JacStack<T>::GetTop(T &t) const
{
    if (top == base) return false;
    
    t= *(top - 1);
    return true;
}

template<class T>
void JacStack<T>::Push(T const &t)
{
    if ((top - base) >= stacksize) expendStack();
    *(top++) = t;
}

template<class T>
bool JacStack<T>::Pop(T &t)
{
    if (top == base) false;
    t = *(--top);
    return true;
}

template<class T>
void JacStack<T>::Traverse(std::function<void(T)> visit) const
{
    T* p = top;
    while(p != base) {
        visit(*(--p));
    }
}

template<class T>
void JacStack<T>::initStack(int initsize)
{
    base = new T[initsize];
    top = base;
    stacksize = initsize;
}

template<class T>
void JacStack<T>::expendStack()
{
    T* newBase = new T[stacksize + STACK_INCREASESIZE];
    T* np = newBase;
    T* p = base;
    while(p != top) {
        *np++ = *p++;
    }
    delete [] base;
    base = newBase;
    top = base + stacksize;
    stacksize += STACK_INCREASESIZE;
}

}

#endif // !_JAC_STACK_H
