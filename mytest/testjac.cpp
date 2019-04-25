#include<iostream>
#include<string>

#include "Jac.h"
#include "mathf.h"

using namespace std;
using namespace Jac;
using namespace mathf;

int test_JacList();
int test_JacStack();

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "parameter error" << std::endl;
        return -1; 
    }

    int a = atoi(argv[1]);
    if (a == 1)
        return test_JacStack();
    else if (a == 2)
        return test_JacList();

    return 1;
}

// 测试JacStack
int test_JacStack()
{
    int res = 0;
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
                res = 1;
                break;
            }
        } else {
            res = 2;
            break;
        }
        cout<<num<<endl;
    }

    delete S;
    return res;
}

// 测试JacList
int test_JacList()
{
    int res = 0;
    int i = 0;
    int testLeng = 1500;

    JacList<float>* JList = new JacList<float>();

    for (i = 0; i < testLeng; i++) {
        JList->Append((float)i);
    }
    JList->Insert(3, 4.55f);

    int len = JList->Length();
    for (i = 0; i < len; i++) {
        if (3 == i) {
            if ((*JList)[i] != 4.55f) {
                res = 1;
                break;
            }
        } else if (i < 3) {
            if ((*JList)[i] != (float)i) {
                res = 2;
                break;
            }
        } else {
            if ((*JList)[i] != (float)(i - 1)) {
                res = 3;
                break;
            }
        }
        cout<<(*JList)[i]<<endl;
    }
    
    delete JList;

    return res;
}
