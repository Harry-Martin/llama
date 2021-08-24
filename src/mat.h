#ifndef LL_MAT_H
#define LL_MAT_H

#include "llama.h"

typedef struct
{
    unsigned int rows;
    unsigned int columns;
    float** elements;
    /* elements[rows][columns] */
} llmat;

#define LL_MAT_UNDEFINED ((llmat) { 0, 0, NULL })

/**
 * Allocate the memory for a [`rows` x `columns`] matrix.
 */
llmat ll_allocateMat(unsigned int rows, unsigned int columns);

/**
 * Free the memory allocated on the heap for matrix `m`.
 */
void ll_freeMat(llmat m);

/**
 * Print out a matrix to the standard output stream using printf().
 */
void ll_printMat(llmat m);

/**
 * Construct a [`rows` x `columns`] matrix and fill it with `defaultValue`.
 */
llmat ll_defaultMat(unsigned int rows, unsigned int columns, float defaultValue);

/**
 * Returns a [`rows` x `columns`] matrix populated with the rows*columns arugments that follow.
 */
llmat ll_matrix(unsigned int rows, unsigned int columns, ...);

/**
 * Returns a [`dimension x dimension`] identity matrix.
 */
llmat ll_identityMat(unsigned int dimension);

/**
 * Returns a copy of matrix `m`.
 */
llmat ll_copyMat(llmat m);

/**
 * Returns `true` if both matrix `A` and `B` have the same dimensionality.
 */
bool ll_sameDimMat(llmat A, llmat B);

/**
 * Returns `true` if Matrix `A` == Matrix `B`. Returns false otherwise.
 */
bool ll_equalMat(llmat A, llmat B);

/**
 * Returns the sum of matrix `A` and `B`.
 */
llmat ll_addMat(llmat A, llmat B);

/**
 * Returns the result of subtraction of matrix `B` from matrix `A`.
 */
llmat ll_subMat(llmat A, llmat B);

/**
 * Returns the result of element-wise multiplication of matrix `A` and matrix `B`.
 */
llmat ll_mulMat(llmat A, llmat B);

/**
 * Returns the result of element-wise division of matrix `A` by matrix `B`.
 */
llmat ll_divMat(llmat A, llmat B);

/**
 * Returns the result of matrix multiplication of `A` and `B`.
*/
llmat ll_dotMat(llmat A, llmat B);

/**
 * Returns the transposition of the matrix `A`. Turns matrix [i x j] into matrix [j x i]
 */
llmat ll_transposeMat(llmat m);
#endif
