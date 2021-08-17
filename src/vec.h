#ifndef VEC_H
#define VEC_H

typedef struct
{
    unsigned int order;
    float* components;
} vec;

#define VEC_UNDEFINED ({ 0, NULL })

/**
 * print vector, `v`, to the standard output stream using printf.
 */
void print(vec* v);

/**
 * allocate the memory for a vector with `order` number of components.
 */
vec allocate(unsigned int order);

/**
 * construct a vector of `order` and fill it with `defaultValue`
 */
vec defaultVector(unsigned int order, float defaultValue);

/**
 * construct a vector of `order` and populate it with `...`
 */
vec newVector(unsigned int order, ...);

/**
 * macro: call `newVector()` without specifying the number of arugments
 */
#define vector(...) (newVector(sizeof((float[]) { __VA_ARGS__ }) / sizeof(float), __VA_ARGS__))

vec add(vec a, vec b);
vec sub(vec a, vec b);
vec mul(vec a, vec b);
/* vec div(vec a, vec b); */

#endif
