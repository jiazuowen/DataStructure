/**
 * 数据结构  栈
 * Author   Jack
 * Date     2019-04-23
 */
#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>
#include "Advance.h"

#define STACK_INIT_SIZE     100         
#define STACKINCREMENT      10

typedef char SElemType;

typedef struct {
    SElemType*      base;
    SElemType*      top;
    int             stacksize;
} SqStack;

typedef Status (* SqStackTraverse)(SElemType* item);

/**
 * 初始化栈
*/
Status InitStack(SqStack &S);

/**
 * 销毁栈
*/
Status DestroyStack(SqStack &S);

/**
 * 清空栈
*/
Status ClearStack(SqStack &S);

/**
 * 返回栈的长度
*/
int StackLength(SqStack S);

/**
 * 栈是否为空
*/
Status StackEmpty(const SqStack &S);

/**
 * 获取栈顶元素
*/
Status GetTop(const SqStack &S, SElemType &e);

/**
 * 入栈
*/
Status Push(SqStack &S, SElemType e);

/**
 * 出栈
*/
Status Pop(SqStack &S, SElemType &e);

/**
 * 遍历栈，使用visit函数处理每一个栈元素
*/
Status StackTraverse(SqStack S, SqStackTraverse visit);

#endif