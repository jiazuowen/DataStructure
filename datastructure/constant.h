#ifndef _CONSTANT_H
#define _CONSTANT_H

#ifdef __cplusplus
extern "C" {
#endif

#define TRUE        1
#define FALSE       0

#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define UNDERFLOW   -3

#define NULLPTR     0

typedef int Status;

typedef int ElemType;

typedef int BOOL;

#define MALLOC(x)  malloc(x)
#define FREE(x) free(x)
#define NOWILD(x) x=NULLPTR

#ifdef __cplusplus
}
#endif

#endif