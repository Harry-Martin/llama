#ifndef LL_VEC_H
#define LL_VEC_H

#include "llama.h"

typedef struct
{
    unsigned int order;
    float* components;
} llvec;

#define LL_VEC_UNDEFINED ((llvec) { 0, NULL })

/**
 * allocate the memory for a vector with `order` number of components.
 */
llvec ll_allocateVec(unsigned int order);

/**
 * free the heap allocated memory for vector `v`.
 */
void ll_freeVec(llvec v);

/**
 * construct a vector of `order` and fill it with `defaultValue` and return it.
 */
llvec ll_defaultVec(unsigned int order, float defaultValue);

/**
 * construct a vector of `order` and populate it with `...` and return it.
 */
llvec ll_newVec(unsigned int order, ...);

/**
 * macro: call `newVector()` without specifying the number of arugments.
 */
#define ll_vec(...) (ll_newVec(sizeof((float[]) { __VA_ARGS__ }) / sizeof(float), __VA_ARGS__))

/**
 * return a copy of vector `v`.
 */
llvec ll_copyVec(llvec v);

/**
 * check that two vectors are equivilent
 */
bool ll_sameVec(llvec a, llvec b);

/**
 * sum of vectors `a` and `b`.
*/
llvec ll_addVec(llvec a, llvec b);

/**
 *  subtraction of vectors `a` and `b`.
 */
llvec ll_subVec(llvec a, llvec b);

/**
 * component-wise multipliction of vectors `a` and `b`.
 */
llvec ll_mulVec(llvec a, llvec b);

/**
 * component-wise division of vectors `a` and `b`.
 */
llvec ll_divVec(llvec a, llvec b);

/**
 * scalar addition of vector `v` and scalar `s`.
 */
llvec ll_scalarAddVec(llvec v, float s);

/**
 * scalar subtraction of vector `v` and scalar `s`.
 */
llvec ll_scalarSubVec(llvec v, float s);

/**
 * scalar multiplication of vector `v` and scalar `s`.
 */
llvec ll_scalarMulVec(llvec v, float s);

/**
 * scalar division of vector `v` and scalar `s`.
 */
llvec ll_scalarDivVec(llvec v, float s);

/**
 * return the magnitude of vector `v`.
 */
float ll_magVec(llvec v);

/**
 * return the normal of vector `v`.
 */
llvec ll_normVec(llvec v);

/**
 * return the dot product of vectors `a` and `b`.
 */
float ll_dotVec(llvec a, llvec b);

/**
 * return the angle between two vectors
 */
float ll_angleVec(llvec a, llvec b);

/**
 * return the cross product of vectors `a` and `b`.
 * NOTE: the cross product is only defined for vectors of order 3.
 */
llvec ll_crossVec(llvec a, llvec b);

#endif
