/**
 * 数据结构  栈
 * Author   Jack
 * Date     2019-04-23
 */
#include "SqStack.h"

Status InitStack(SqStack &S)
{
    S.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S)
{
    free((void *)S.base);
    S.base = 0;
    S.top = 0;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

int StackLength(SqStack S)
{
    return S.stacksize;
}

Status StackEmpty(const SqStack &S)
{
    if (S.top == S.base) return TRUE;
    return FALSE;
}

Status GetTop(const SqStack &S, SElemType &e)
{
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) exit (OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base) return ERROR;
    e = * --S.top;
    return OK;
}

Status StackTraverse(SqStack S, SqStackTraverse visit)
{
    SElemType* p = S.top;
    while (p != S.base)
    {
        visit(p - 1);
        p--;
    }
    return OK;
}