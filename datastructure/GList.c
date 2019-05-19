/**
 * 广义表
 * 
 * Date : 2019-05-19
 * Author : Jack
*/
#include "GList.h"

Status InitGList(GList* L)
{
    return ERROR;
}

Status CreateGList(GList* L, const GList* S)
{
    return ERROR;
}

Status DestroyGList(GList* L)
{
    return ERROR;
}

Status CopyGList(GList* T, const GList* L)
{
    return ERROR;
}

Status GListLength(const GList* L)
{
    return ERROR;
}

Status GListDepth(const GList* L)
{
    return ERROR;
}

Status GListEmpty(const GList* L, BOOL* empty)
{
    return ERROR;
}

Status GListHead(const GList* L, GList* head)
{
    return ERROR;
}

Status GListTail(const GList* L, GList* tail)
{
    return ERROR;
}

Status InsertFirst_GL(GList* L,  const GList* e)
{
    return ERROR;
}

Status DeleteFirst_GL(GList* L, GList* e)
{
    return ERROR;
}

Status Traverse_GL(GList* L, Status (*Visit)(GList* e))
{
    return ERROR;
}
