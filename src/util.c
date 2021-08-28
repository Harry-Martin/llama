#include <math.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

llmat ll_rotationMat(float x, float y, float z)
{
    llmat rotX = ll_mat(4, 4,
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cosf(x), -sinf(x), 0.0f,
        0.0f, sinf(x), cosf(x), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);

    llmat rotY = ll_mat(4, 4,
        cosf(y), 0.0f, sinf(y), 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -sinf(y), 1.0f, cosf(y), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);

    llmat rotZ = ll_mat(4, 4,
        cosf(z), -sinf(z), 0.0f, 0.0f,
        sinf(z), cosf(z), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);

    llmat out = ll_dotMat(ll_dotMat(rotZ, rotY), rotX);

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

