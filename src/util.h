#ifndef LL_UTIL_H
#define LL_UTIL_H

#include "mat.h"
#include "vec.h"

/**
 * Return a [4 x 4] rotation matrix which, when multiplied by a 4-dimenional homogeneous point, will rotate the point by `x`, `y` and `z` radians (clockwise) in the appropriate axis.
 * NOTE: The rotations are defined by XYZ where X, Y, and Z are matrices which define a rotation in their corresponding axis. In general matrix multiplication is not commutative so this order is important to keep in mind.
 */
llmat ll_rotationMat(float x, float y, float z);

/**
 * Return a matrix which has been multiplied by a rotation matrix defined by rotations `x` `y` `z` about each corresponding axis
 * NOTE: this function is only defined for [3 x 3] matrices.
 */
llmat ll_rotateMat(llmat m, float x, float y, float z);


/**
 * print vector, `v`, to the standard output stream using printf.
 */
void ll_printVec(llvec v);


/**
 * Print out a matrix to the standard output stream using printf().
 */
void ll_printMat(llmat m);
#endif /* LL_UTIL_H */
