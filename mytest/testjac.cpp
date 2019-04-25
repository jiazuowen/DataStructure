#include<iostream>
#include<string>

#include "Jac.h"
#include "mathf.h"

using namespace std;
using namespace Jac;
using namespace mathf;

void test_JacList();
void test_JacStack();
void test_JacQueue();
void test_JacArray();

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "parameter error" << std::endl;
        return -1; 
    }
    int a = atoi(argv[1]);

    if (a == 1)
        test_JacStack();
    else if (a == 2)
        test_JacList();
    else if (a == 3)
        test_JacQueue();
    else if (a == 4)
        test_JacArray();

    return 1;
}

// 测试JacStack
void test_JacStack()
{
    string res = "ok";
    int i = 0;
    int testLeng = 15000;

    JacStack<int>* S = new JacStack<int>();

    for (i = 0; i < testLeng; ++i) {
        S->Push(i);
    }
    for (i = 0; i < testLeng; ++i) {
        int num;
        if (S->Pop(num)) {
            if (num != (testLeng - i - 1)) {
                res = "not equet";
                break;
            }
        } else {
            res = "error pop";
            break;
        }
    }
    delete S;
    cout<<res<<endl;
}

// 测试JacList
void test_JacList()
{
    string res = "ok";
    int i = 0;
    int testLeng = 15000;

    JacList<float>* JList = new JacList<float>();

    for (i = 0; i < testLeng; i++) {
        JList->Append((float)i);
    }
    JList->Insert(3, 4.55f);

    int len = JList->Length();
    for (i = 0; i < len; i++) {
        if (3 == i) {
            if ((*JList)[i] != 4.55f) {
                res = "not 4.55";
                break;
            }
        } else if (i < 3) {
            if ((*JList)[i] != (float)i) {
                res = "not ==";
                break;
            }
        } else {
            if ((*JList)[i] != (float)(i - 1)) {
                res = "not ==";
                break;
            }
        }
    }
    
    delete JList;
    cout<<res<<endl;
}

// 测试队列数据结构
void test_JacQueue()
{
    string res = "ok";
    int i = 0;
    int testLengh = 15000;

    JacQueue<double>* queue = new JacQueue<double>();
    for (i = 0; i < testLengh; ++i) {
        queue->Enqueue((double)i);
    }

    for (i = 0; i < testLengh; ++i) {
        double num;
        if (queue->Dequeue(num)) {
            if (num != (double)i) {
                res = "not equent";
                break;
            }
        } else {
            res = "valid length";
            break;
        }
    }

    delete queue;
    cout<<res<<endl;
}

// 测试数组数据结构
void test_JacArray()
{
    string res = "ok";
    JacArray<string>* strArray = new JacArray<string>(100);
    for (int i = 0; i < 100; ++i) {
        (*strArray)[i] = "hello jack";
    }
    for (int i = 0; i < 100; ++i) {
        if ((*strArray)[i] != "hello jack") {
            res = "not";
        }
    }
    delete strArray;
    cout<<res<<endl;
}
