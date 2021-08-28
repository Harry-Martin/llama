#include <math.h>
#include <stdio.h>

#include "util.h"


llmat ll_rotationMat(float x, float y, float z)
{
    float cosx = cosf(x);
    float cosy = cosf(y);
    float cosz = cosf(z);
    float sinx = sinf(x);
    float siny = sinf(y);
    float sinz = sinf(z);

    llmat out = ll_mat(3, 3,
        cosx * cosy * cosz - sinx * sinz, -cosx * cosy * sinz - sinx * cosz, cosx * siny,
        sinx * cosy * cosz + cosx * sinz, -sinx * cosy * sinz + cosx * cosz, sinx * siny,
        -siny * cosz, siny * sinz, cosy);

    return out;
}

llmat ll_rotateMat(llmat m, float x, float y, float z)
{
    llmat R = ll_rotationMat(x, y, z);
    return ll_dotMat(m, R);
}

void ll_printVec(llvec v)
{
    printf("[ ");
    if (ll_sameVec(v, LL_VEC_UNDEFINED))
    {
        printf("UNDEFINED ");
    }
    for (unsigned int i = 0; i < v.order; i++)
    {
        printf("%f", v.components[i]);
        if (i != v.order - 1)
        {
            printf(", ");
        }
        else
        {
            printf(" ");
        }
    }
    printf("]\n");
}

void ll_printMat(llmat m)
{
    if (ll_equalMat(m, LL_MAT_UNDEFINED))
    {
        printf("| UNDEFINED |\n");
    }
    for (unsigned int i = 0; i < m.rows; i++)
    {
        printf("| ");
        for (unsigned int j = 0; j < m.columns; j++)
        {
            printf("%6.*f ", 2, m.elements[i][j]);
        }
        printf("| \n");
    }
}

