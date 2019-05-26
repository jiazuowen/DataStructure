/**
 * 广义表
 * 
 * Date : 2019-05-19
 * Author : Jack
*/
#include "GList.h"
#include <stdlib.h>

Status InitGList(GList* L)
{
    GLNode* p = (GLNode*)MALLOC(sizeof(GLNode));
    if (!p) exit(OVERFLOW);
    p->tag = LIST;
    p->hp = NULLPTR;
    p->tp = NULLPTR;
    *L = p;
    return OK;
}

Status CreateGList(GList* L, const GList S)
{
    Status s = InitGList(L);
    if (s != OK) return s;
    return CopyGList(*L, S);
}

Status DestroyGList(GList* L) // 递归函数
{
    Status s;

    if (!*L) return ERROR;

    GLNode* p = (*L)->hp;

    if (p) {
        s = DestroyGList(&p);
        if (s != OK) return s;
    }

    GLNode* n = (*L)->tp;
    while (n)
    {
        s = DestroyGList(&n);
        if (s != OK) return s;
        n = n->tp;
    }
    
    FREE(*L);
    *L = NULLPTR;
    
    return OK;
}

Status CopyGList(GList T, const GList L)
{
    return ERROR;
}

Status GListLength(const GList L, int* lenght) // 递归函数
{
    int len;
    if (!L) return ERROR;
    if (L->tag == LIST && !L->hp && !L->tp) { 
        *lenght = 0;
        return OK;
    }
    if (L->tag == ATOM) {
        *lenght = 1;
    } else {
        Status s = GListLength(L->hp, &len);
        if (s != OK) return s;
        *lenght = len;
    }
    GLNode* p = L->tp;
    while (p)
    {
        Status s = GListLength(p, &len);
        if (s != OK) return s;
        *lenght += len;
    }
    return OK;
}

Status GListDepth(const GList L, int* depth) //递归函数
{
    if (!L) return ERROR;
    if (L->tag == LIST && !L->hp && !L->tp) { 
        *depth = 1;
        return OK;
    }
    if (L->tag == ATOM) { 
        *depth = 0;
        return OK;
    }

    int max = 0;
    GLNode* p = L->hp;
    while (p)
    {
        int temp;
        GListDepth(p, &temp);
        if (temp > max)
            max = temp;
        p = p->tp;
    }
    *depth = max + 1;
    
    return OK;
}

Status GListEmpty(const GList L, BOOL* empty)
{
    if (!L) return ERROR;
    *empty = L->tag == LIST && !L->hp && !L->tp;
    return OK;
}

GLNode* getHead(const GList L) // 递归函数
{
    if (L->tag == ATOM) {
        return L;
    }
    if (L->tag == LIST && !L->hp && !L->tp) {
        return L;
    }
    return getHead(L->hp);
}

GLNode* getTail(const GList L) // 递归函数
{
    GLNode* p = L;
    while (p->tp) {
        p = p->tp;
    }
    if (p->tag == ATOM) {
        return L;
    }
    if (p->tag == LIST && !p->hp && !p->tp) {
        return L;
    }
    return getTail(p);
}

Status GListHead(const GList L, GLNode* head) // 递归函数
{
    if (!L) return ERROR;
    GLNode* p = getHead(L);
    if (!p) return ERROR;
    if (p->tag == ATOM) {
        head->tag = ATOM;
        head->atom = p->atom;
    } else {
        head->tag = LIST;
        head->hp = NULLPTR;
    }
    head->tp = NULLPTR;
    return OK;
}

Status GListTail(const GList L, GLNode* tail) // 递归函数
{
    if (!L) return ERROR;
    GLNode* p = getTail(L);
    if (!p) return ERROR;
    if (p->tag == ATOM) {
        tail->tag = ATOM;
        tail->atom = p->atom;
    } else {
        tail->tag = LIST;
        tail->hp = NULLPTR;
    }
    tail->tp = NULLPTR;
    return OK;
}

Status InsertFirst_GL(GList L, const GLNode e)
{
    // if (!L) return ERROR;
    // GLNode* p = getHead(L);
    // GLNode* n = (GLNode*)MALLOC(sizeof(GLNode));
    // n->tag = e.tag;
    // if (e.tag == ATOM)
    //     n->atom = e.atom;
    // else 
        
    return OK;
}

Status DeleteFirst_GL(GList L, GLNode* e)
{
    return ERROR;
}

Status Traverse_GL(GList L, Status (*Visit)(GLNode e))
{
    return ERROR;
}
