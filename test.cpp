#include <iostream>

#include "SqStack.h"
#include "mathf.h"

using namespace std;
using namespace Sq;

SqStack S;
int N = 100;
int H = 8;

int main()
{
    InitStack(S);
    while (N)
    {
        Push(S, N % H);
        N = N / H;
    }

    StackTraverse(S, [](SElemType* t){
        printf("Traverse:%d\n", *t);
    });
    
    while (!StackEmpty(S))
    {
        char e;
        Pop(S, e);
    }
    DestroyStack(S);

    printf("\n");
    int num = 6;
    num += add(5 , 6);
    cout<<"add result:"<<num<<endl;
    cout<<"Hello Jack"<<endl;
    return 0;
}