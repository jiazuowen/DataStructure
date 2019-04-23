#include <iostream>

#include "SqStack.h"
#include "math.h"

using namespace std;

SqStack S;
int N = 100;
int H = 8;

Status visiter(SElemType* item);

int main()
{
    InitStack(S);
    while (N)
    {
        Push(S, N % H);
        N = N / H;
    }

    StackTraverse(S, visiter);
    
    while (!StackEmpty(S))
    {
        char e;
        Pop(S, e);
        //printf("%d", e);
    }
    DestroyStack(S);

    printf("\n");
    int num = 6;
    num += add(5 , 6);
    cout<<"add result:"<<num<<endl;
    cout<<"Hello Jack"<<endl;
    return 0;
}

Status visiter(SElemType* item)
{
    printf("%d", *item);
    return OK;
}