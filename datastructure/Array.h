/**
 * C语言版多维数组
*/

#ifndef _ARRAY_H
#define _ARRAY_H

#include <stdarg.h>
#include <stdlib.h>
#include "constant.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ARRAY_DIM       8

typedef int ElemType;

typedef struct {
    ElemType* base;
    int dim;
    int* bounds;
    int* constants;
} Array;

Status InitArray(Array* A, int dim, ...);

Status DestroyArray(Array* A);

Status Value(const Array* A, ElemType* e, ...);

Status Assign(Array* A, ElemType e, ...);

#ifdef __cplusplus
}
#endif

#endif