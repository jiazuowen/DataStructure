/**
 * 广义表
 * 
 * Date : 2019-05-19
 * Author : Jack
*/
#ifndef _GLIST_H
#define _GLIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "constant.h"

typedef int AtomType;

typedef enum {
    ATOM,   // 原子类型
    LIST    // 子表
} ElemTag;

typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom;      // 原子节点的值域
        struct GLNode *hp;  // 表节点的表头指针
    };
    struct GLNode *tp;
} *GList;

/**
 * 创建空的广义表
*/
Status InitGList(GList* L);

/**
 * 由S创建广义表L
*/
Status CreateGList(GList* L, const GList* S);

/**
 * 销毁广义表
*/
Status DestroyGList(GList* L);

/**
 * 由广义表L复制到T
*/
Status CopyGList(GList* T, const GList* L);

/**
 * 求广义表L的长度，元素个数
*/
Status GListLength(const GList* L);

/**
 * 求广义表的深度
*/
Status GListDepth(const GList* L);

/**
 * 判断广义表是否为空
*/
Status GListEmpty(const GList* L, BOOL* empty);

/**
 * 获取广义表的头
*/
Status GListHead(const GList* L, GList* head);

/**
 * 取广义表的尾
*/
Status GListTail(const GList* L, GList* tail);

/**
 * 插入元素e作为广义表的第一个元素
*/
Status InsertFirst_GL(GList* L,  const GList* e);

/**
 * 删除广义表的第一个元素，并返回到e
*/
Status DeleteFirst_GL(GList* L, GList* e);

/**
 * 遍历广义表L，用函数visit处理每个元素
*/
Status Traverse_GL(GList* L, Status (*Visit)(GList* e));


#ifdef __cplusplus
}
#endif

#endif