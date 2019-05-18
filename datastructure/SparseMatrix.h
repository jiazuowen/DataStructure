/**
 * C语言版稀疏矩阵
*/
#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "constant.h"

#define MAXSIZE 12500

typedef struct {
    int i,j;
    ElemType e;
} Triple; // 三元组

typedef struct {
    Triple* data;
    int mu, nu, tu; //矩阵的行、列、非零元的个数
} TSMatrix;

/**
 * 创建矩阵M
*/
Status CreateSMatrix(TSMatrix* M);

/**
 * 销毁矩阵M
*/
Status DestroySMatrix(TSMatrix* M);

/**
 * 打印矩阵M
*/
Status PrintSMatrix(const TSMatrix* M);

/**
 * 复制矩阵
*/
Status CopySMatrix(const TSMatrix* M, TSMatrix* T);

/**
 * 求矩阵和 Q = M + N
 */
Status AddSMatrix(const TSMatrix* M, const TSMatrix* N, TSMatrix* Q);

/**
 * 求矩阵差 Q = M - N
*/
Status SubSMatrix(const TSMatrix* M, const TSMatrix* N, TSMatrix* Q);

/**
 * 求矩阵乘积 Q = M X N
*/
Status MultSMatrix(const TSMatrix* M, const TSMatrix* N, TSMatrix* Q);

/**
 * 求M的转置矩阵T
*/
Status TransposeSMatrix(const TSMatrix* M, TSMatrix* T);

#ifdef __cplusplus
}
#endif

#endif //!_SPARSEMATRIX_H