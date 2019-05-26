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

Status GListLength(const GList L, int* lenght)
{
    return ERROR;
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

Status GListHead(const GList L, GLNode* head)
{
    // if (!L) return ERROR;
    // if (L->tag == ATOM) {
    //     head = L;
    //     return OK;
    // }
    // head = L->hp;

    return OK;
}

Status GListTail(const GList L, GLNode* tail)
{
    // if (!L) return ERROR;
    // if (L->tag == ATOM) {
    //     tail = L;
    //     return OK;
    // }
    // GLNode* p = L->hp;
    // while (p->tp) {
    //     p = p->tp;
    // }
    // tail = p;
    
    return OK;
}

Status InsertFirst_GL(GList L,  const GLNode e)
{
    return ERROR;
}

Status DeleteFirst_GL(GList L, GLNode* e)
{
    return ERROR;
}

Status Traverse_GL(GList L, Status (*Visit)(GLNode e))
{
    return ERROR;
}
