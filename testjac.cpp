#include<iostream>
#include<string>
#include "JacStack.h"
#include "JacList.h"

using namespace std;
using namespace Jac;


int main()
{
    JacStack<int>* S = new JacStack<int>();
    JacStack<string>* strstack = new JacStack<string>();
    JacList<float>* StrList = new JacList<float>();

    for (int i = 0; i < 150; ++i) {
        S->Push(i);
    }
    S->StackTraverse([](int t){
        cout<<"traverse:"<<t<<endl;
    });

    
    for (int i = 0; i < 6; ++i) {
        strstack->Push("Hello Jack");
    }
    strstack->StackTraverse([](string str){
        cout<<str<<endl;
    });

    for (int i = 0; i < 10; i++) {
        StrList->Append((float)i);
    }
    StrList->Insert(3, 4.55f);
    cout<<"List Length:"<<StrList->Length()<<endl;
    // StrList->Traverse([](float f){
    //     cout<<"f:"<<f<<endl;
    // });
    for (int i = 0; i < StrList->Length(); i++) {
        cout<<"[f]="<<(*StrList)[i]<<endl;
    }
    
    delete StrList;
    delete S;
    delete strstack;

    return 0;
}