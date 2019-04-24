#include<iostream>
#include<string>
#include "JacStack.h"

using namespace std;
using namespace Jac;


int main()
{
    JacStack<int>* S = new JacStack<int>();

    for (int i = 0; i < 150; ++i) {
        S->Push(i);
    }
    S->StackTraverse([](int t){
        cout<<"traverse:"<<t<<endl;
    });

    JacStack<string>* strstack = new JacStack<string>();
    for (int i = 0; i < 6; ++i) {
        strstack->Push("Hello Jack");
    }
    strstack->StackTraverse([](string str){
        cout<<str<<endl;
    });
    
    delete S;

    return 0;
}