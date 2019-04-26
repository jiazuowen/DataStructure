/**
 * 数据结构  队列 (使用C++模板类实现，需要C++11标准)
 * Author Jack
 * Date 2019-04-25
*/
#ifndef _JAC_QUEUE_H
#define _JAC_QUEUE_H

#include <functional>
using namespace std;

namespace Jac
{

#define QUEUE_INIT_SIZE 100
#define QUEUE_INCREASESIZE 10

template<class T>
class JacQueue
{
    T*  base;
    T*  head;
    T*  tail;
    int length;
    int queuesize;
public:
    JacQueue();
    JacQueue(int initSize);
    ~JacQueue();

    void Clear();
    int Length() const;
    bool Empty() const;
    bool GetHead(T &t) const;
    void Enqueue(T const &t);
    bool Dequeue(T &t);
    void Traverse(std::function<void(T)> visit) const;
private:
    void initQueue(int initsize);
    void expendQueue();
};

template<class T>
JacQueue<T>::JacQueue()
{
    initQueue(QUEUE_INIT_SIZE);
}

template<class T>
JacQueue<T>::JacQueue(int initSize)
{
    initQueue(initSize);
}

template<class T>
JacQueue<T>::~JacQueue()
{
    delete [] base;
    base = nullptr;
    head = nullptr;
    tail = nullptr;
    length = 0;
    queuesize = 0;
}

template<class T>
void JacQueue<T>::Clear()
{
    head = base;
    tail = base;
    length = 0;
}

template<class T>
int JacQueue<T>::Length() const
{
    return length;
}

template<class T>
bool JacQueue<T>::Empty() const
{
    return length == 0;
}

template<class T>
bool JacQueue<T>::GetHead(T &t) const
{
    if (length <= 0) return false;
    t = *head;
    return true;
}

template<class T>
void JacQueue<T>::Enqueue(T const &t)
{
    if (length >= queuesize) expendQueue();

    if ((tail - base) >= queuesize) {
        tail = base;
        *tail = t;
    } else {
        *tail++ = t;
    }
    length++;
}

template<class T>
bool JacQueue<T>::Dequeue(T &t)
{
    if (length <= 0) return false;
    t = *head++;
    length--;
    return true;
}

template<class T>
void JacQueue<T>::Traverse(std::function<void(T)> visit) const
{
    T* p = head;
    for (int i = 0; i < length; ++i) {
        visit(*p);
        if ((p - base) >= queuesize) {
            p = base;
        } else {
            p++;
        }
    }
}

template<class T>
void JacQueue<T>::initQueue(int initsize)
{
    base = new T[initsize];
    head = base;
    tail = base;
    length = 0;
    queuesize = initsize;
}

template<class T>
void JacQueue<T>::expendQueue()
{
    T* newbase = new T[queuesize + QUEUE_INCREASESIZE];
    T* newp = newbase;
    T* p = head;
    for (int i = 0; i < length; ++i) {
        *newp++ = *p;
        if ((p - base) >= queuesize) {
            p = base;
        } else {
            p++;
        }
    }
    delete [] base;
    base = newbase;
    head = base;
    tail = head + length;
    queuesize += QUEUE_INCREASESIZE;
}

}

#endif // !_JAC_QUEUE_H
