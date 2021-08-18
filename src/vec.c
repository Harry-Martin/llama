#include "vec.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void ll_printVec(llvec* v)
{
    printf("[ ");
    if (ll_sameVec(*v, LL_VEC_UNDEFINED))
    {
        printf("UNDEFINED ");
    }
    for (unsigned int i = 0; i < v->order; i++)
    {
        printf("%f", v->components[i]);
        if (i != v->order - 1)
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

llvec ll_allocateVec(unsigned int order)
{
    llvec v;
    v.order = order;
    v.components = (float*)malloc(order * sizeof(float));

    return v;
}

llvec ll_defaultVec(unsigned int order, float defaultValue)
{
    llvec v = ll_allocateVec(order);
    for (unsigned int i = 0; i < order; i++)
    {
        v.components[i] = defaultValue;
    }
    return v;
}

llvec ll_newVec(unsigned int order, ...)
{
    llvec v = ll_allocateVec(order);
    va_list args;

    va_start(args, order);
    for (unsigned int i = 0; i < order; i++)
    {
        float value = va_arg(args, double);
        v.components[i] = value;
    }
    va_end(args);

    return v;
}

llvec ll_copyVec(llvec v)
{
    return v;
}

bool ll_sameVec(llvec a, llvec b)
{
    if (a.order == b.order)
    {
        for (unsigned int i = 0; i < a.order; i++)
        {
            if (a.components[i] != b.components[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

llvec ll_addVec(llvec a, llvec b)
{
    if (a.order == b.order)
    {
        for (unsigned int i = 0; i < a.order; i++)
        {
            a.components[i] += b.components[i];
        }
        return a;
    }
    else
    {
        return LL_VEC_UNDEFINED;
    }
}

llvec ll_subVec(llvec a, llvec b)
{
    if (a.order == b.order)
    {
        for (unsigned int i = 0; i < a.order; i++)
        {
            a.components[i] -= b.components[i];
        }
        return a;
    }
    else
    {
        return LL_VEC_UNDEFINED;
    }
}

llvec ll_mulVec(llvec a, llvec b)
{
    if (a.order == b.order)
    {
        for (unsigned int i = 0; i < a.order; i++)
        {
            a.components[i] *= b.components[i];
        }
        return a;
    }
    else
    {
        return LL_VEC_UNDEFINED;
    }
}

llvec ll_divVec(llvec a, llvec b)
{
    if (a.order == b.order)
    {
        for (unsigned int i = 0; i < a.order; i++)
        {
            a.components[i] /= b.components[i];
        }
        return a;
    }
    else
    {
        return LL_VEC_UNDEFINED;
    }
}

llvec ll_scalarAddVec(llvec v, float s)
{
    for (unsigned int i; i < v.order; i++)
    {
        v.components[i] += s;
    }
    return v;
}

llvec ll_scalarSubVec(llvec v, float s)
{
    for (unsigned int i; i < v.order; i++)
    {
        v.components[i] -= s;
    }
    return v;
}

llvec ll_scalarMulVec(llvec v, float s)
{
    for (unsigned int i; i < v.order; i++)
    {
        v.components[i] *= s;
    }
    return v;
}

llvec ll_scalarDivVec(llvec v, float s)
{
    for (unsigned int i; i < v.order; i++)
    {
        v.components[i] /= s;
    }
    return v;
}

float ll_magVec(llvec v)
{
    if (ll_sameVec(v, LL_VEC_UNDEFINED))
    {
        return 0.0f;
    }
    float squared_sum = 0;
    for (unsigned int i = 0; i < v.order; i++)
    {
        squared_sum += v.components[i] * v.components[i];
    }
    return sqrtf(squared_sum);
}

llvec ll_normVec(llvec v)
{
    return ll_scalarDivVec(v, ll_magVec(v));
}
