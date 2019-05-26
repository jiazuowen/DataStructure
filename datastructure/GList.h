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
    struct GLNode *tp;      // 指向以一个元素的节点
} *GList, GLNode;

/**
 * 创建空的广义表
 * @pre *L==0;
 * @post *L!=0,*L->tag==LIST,*L->hp==0,*L->tp==0, when return OK
*/
Status InitGList(GList* L);

/**
 * 由S创建广义表L
 * @pre *L==0
 * @pre S!=0
 * @post *L!=0,*L->tag==LIST,*L->hp==0,*L->tp==0, when return OK
*/
Status CreateGList(GList* L, const GList S);

/**
 * 销毁广义表
 * @pre *L!=0
 * @post *L==0, when return OK
*/
Status DestroyGList(GList* L);

/**
 * 由广义表L复制到T
 * @pre T!=0
 * @pre L!=0
 * @post T==L, when return OK
*/
Status CopyGList(GList T, const GList L);

/**
 * 求广义表L的长度，元素个数
 * @pre L!=0
 * @post lenght >= 0, when return OK
*/
Status GListLength(const GList L, int* lenght);

/**
 * 求广义表的深度
 * @pre L!=0
 * @post depth>=1, when return OK
*/
Status GListDepth(const GList L, int* depth);

/**
 * 判断广义表是否为空
 * @pre L!=0
 * @post empty== 0 or 1, when return OK
*/
Status GListEmpty(const GList L, BOOL* empty);

/**
 * 获取广义表的头
 * @pre L!=0
 * @post head!=0, when return OK
*/
Status GListHead(const GList L, GLNode* head);

/**
 * 取广义表的尾
 * @pre L!=0
 * @post tail != 0, when return OK
*/
Status GListTail(const GList L, GLNode* tail);

/**
 * 插入元素e作为广义表的第一个元素
 * @pre L!=0
 * @post length++, when return OK
*/
Status InsertFirst_GL(GList L,  const GLNode e);

/**
 * 删除广义表的第一个元素，并返回到e
 * @pre L!=0
 * @post lenght--, when return OK
*/
Status DeleteFirst_GL(GList L, GLNode* e);

/**
 * 遍历广义表L，用函数visit处理每个元素
 * @pre L!=0
 * @post L Not Changed
*/
Status Traverse_GL(GList L, Status (*Visit)(GLNode e));


#ifdef __cplusplus
}
#endif

#endif