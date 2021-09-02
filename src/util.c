#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/mat.h"
#include "../include/util.h"

llmat ll_rotationMat(float x, float y, float z)
{
    float cosx = cosf(x);
    float sinx = sinf(x);
    float cosy = cosf(y);
    float siny = sinf(y);
    float cosz = cosf(z);
    float sinz = sinf(z);
    llmat out = ll_mat(4,4,
            cosy*cosz, -cosx*sinz + sinx*siny*cosz, sinx*sinz + cosx*siny*cosz, 0.0f,
            cosy*sinz, cosx*cosz + sinx*siny*sinz, -sinx*cosz + cosx*siny*sinz, 0.0f,
            -siny, sinx*cosy, cosx*cosy, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
    return out;
}

llmat ll_translationMat(float x, float y, float z)
{
    llmat out = ll_identityMat(4);
    out.elements[0][3] = x;
    out.elements[1][3] = y;
    out.elements[2][3] = z;
    
    return out;
}

llmat ll_scaleMat(float x, float y, float z)
{
    llmat out = ll_identityMat(4);
    out.elements[0][0] = x;
    out.elements[1][1] = y;
    out.elements[2][2] = z;
    
    return out;
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

llmat ll_vecToMat(llvec v)
{
    llmat M = ll_allocateMat(1, v.order);
    memcpy(M.elements[0], v.components, v.order * sizeof(float));

    return M;
}

llvec ll_matToVec(llmat M)
{
    if (M.rows != 1)
    {
        return LL_VEC_UNDEFINED;
    }

    llvec v = ll_allocateVec(M.columns);
    memcpy(v.components, M.elements[0], M.columns * sizeof(float));

    return v;
}

llvec ll_vecDotMat(llvec v, llmat M)
{
    if (v.order != M.rows)
    {
        return LL_VEC_UNDEFINED;
    }

    return ll_matToVec(ll_dotMat(ll_vecToMat(v), M));
}

llmat ll_rotateMat(llmat m, float x, float y, float z)
{
    llmat R = ll_rotationMat(x, y, z);
    return ll_dotMat(m, R);
}

llvec ll_rotateVec(llvec v, float x, float y, float z)
{
    if (v.order != 4)
    {
        return LL_VEC_UNDEFINED;
    }

    return ll_matToVec(ll_rotateMat(ll_vecToMat(v), x, y, z));
}

llmat ll_ortho(float height, float aspect, float near, float far)
{
    float top = height/2;
    float bottom = -top;
    float left = bottom * aspect;
    float right = top * aspect;
    llmat out = ll_mat(4, 4,
        2.0f / (right - left), 0.0f, 0.0f, -((right + left) / (right - left)),
        0.0f, 2.0f / (top - bottom), 0.0f, -((top + bottom) / (top - bottom)),
        0.0f, 0.0f, -2.0f / (far - near), -((far + near) / (far - near)),
        0.0f, 0.0f, 0.0f, 1.0f);

    return out;
}

llmat ll_persp(float fov, float aspect, float near, float far)
{

    float top = tanf(fov / 2) * near;
    float bottom = -top;
    float left = bottom * aspect;
    float right = top * aspect;

    llmat out = ll_mat(4, 4,
        (2 * near) / (right - left), 0.0f, (right + left) / (right - left), 0.0f,
        0.0f, (2 * near) / (top - bottom), (top + bottom) / (top - bottom), 0.0f,
        0.0f, 0.0f, -(far + near) / (far - near), -(2 * far * near) / (far - near),
        0.0f, 0.0f, -1.0f, 0.0f);

    return out;
}

float* ll_matToFloats(llmat M)
{
    float* data = (float*)malloc(M.rows * M.columns * sizeof(float));
    float* cursor = data;
    for (unsigned int i = 0; i < M.rows; i++)
    {
        memcpy(cursor, M.elements[i], M.columns * sizeof(float));
        cursor += M.columns;
    }
    
    return data;
}

float* ll_vecToFloats(llvec v)
{
    float* data = (float*)malloc(v.order * sizeof(float));
    memcpy(data, v.components, v.order * sizeof(float));

    return data;
}
