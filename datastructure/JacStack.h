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

#define INITSIZE 100
#define INCREASESIZE 10

template<class T>
class JacStack {
    T*  base;
    T*  top;
    int stacksize;
public:
    JacStack();
    JacStack(int initSize);
    ~JacStack();

    void ClearStack();
    int StackLength();
    bool StackEmpty();
    T GetTop();
    void Push(T const &t);
    bool Pop(T &t);
    void StackTraverse(std::function<void(T)> visit);
private:
    void InitStack(int initsize);
};

template<class T>
JacStack<T>::JacStack()
{
    InitStack(INITSIZE);
}

template<class T>
JacStack<T>::JacStack(int initsize)
{
    InitStack(initsize);
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
void JacStack<T>::InitStack(int initsize)
{
    base = new T[initsize];
    top = base;
    stacksize = initsize;
}

template<class T>
void JacStack<T>::ClearStack()
{
    top = base;
}

template<class T>
int JacStack<T>::StackLength()
{
    return stacksize;
}

template<class T>
bool JacStack<T>::StackEmpty()
{
    return top == base;
}

template<class T>
T JacStack<T>::GetTop()
{
    return *(top - 1);
}

template<class T>
void JacStack<T>::Push(T const &t)
{
    // 已经到达栈定时，要扩容
    if ((top - base) >= stacksize) {
        T* newBase = new T[stacksize + INCREASESIZE];
        T* np = newBase;
        T* p = base;
        while(p != top) {
            *np++ = *p++;
        }
        delete [] base;
        base = newBase;
        top = base + stacksize;
        stacksize += INCREASESIZE;
    }

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
void JacStack<T>::StackTraverse(std::function<void(T)> visit)
{
    T* p = top;
    while(p != base) {
        visit(*(--p));
    }
}

}

#endif // !_JAC_STACK_H
