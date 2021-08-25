#ifndef LL_UTIL_H
#define LL_UTIL_H

#include "mat.h"
#include "vec.h"

/**
 * Return a [3 x 3] rotation matrix to rotate a 3-dimenional point about each axis by angles `x`, `y`, and `z`.
 * NOTE: this function is only defined for [3 x 3] matrices.
 */
llmat ll_rotationMat(float x, float y, float z);

/**
 * Return a matrix which has been multiplied by a rotation matrix defined by rotations `x` `y` `z` about each corresponding axis
 * NOTE: this function is only defined for [3 x 3] matrices.
 */
llmat ll_rotateMat(llmat m, float x, float y, float z);

#endif /* LL_UTIL_H */
