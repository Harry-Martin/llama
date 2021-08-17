#include "vec.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void print(vec* v)
{
    printf("[ ");
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

vec allocate(unsigned int order)
{
    vec v;
    v.order = order;
    v.components = (float*)malloc(order * sizeof(float));

    return v;
}

vec defaultVector(unsigned int order, float defaultValue)
{
    vec v = allocate(order);
    for (unsigned int i = 0; i < order; i++)
    {
        v.components[i] = defaultValue;
    }
    return v;
}

vec newVector(unsigned int order, ...)
{
    vec v = allocate(order);
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

vec add(vec a, vec b)
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
        return newVector(0, NULL);
    }
}
vec sub(vec a, vec b)
{
}
vec mul(vec a, vec b)
{
}
/* vec div(vec a, vec b) */
/* { */
/* } */
