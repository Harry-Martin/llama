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
 * Macro to call ll_rotationMat with vector `v` instead of 3 floats.
 */
#define ll_vecRotationMat(v) ll_rotationMat(v.components[0], v.components[1], v.components[2])

/**
 * Return a matrix which has been multiplied by a rotation matrix defined by rotations `x` `y` `z` about each corresponding axis
 * NOTE: this function is only defined for [4 x 4] matrices.
 */
llmat ll_rotateMat(llmat m, float x, float y, float z);

/**
 * Macro to call ll_rotate with matrix `m` and `r` instead of a matrix and 3 floats
 */
#define ll_vecRotateMat(m, r) ll_rotateMat(m, r.components[0],r.components[1],r.components[2])

/**
 * Return a vector which has been multiplied by a rotation matrix defined by rotations `x` `y` `z` about each corresponding axis
 * NOTE: this function is only defined for vectors of order 4.
 */
llvec ll_rotateVec(llvec v, float x, float y, float z);

/**
 * Macro to call ll_rotateVec with vectors `v` and `r` instead of a vector and 3 floats
 */
#define ll_vecRotateVec(v, r) ll_rotateVec(v, r.components[0],r.components[1],r.components[2])

/**
 * print vector, `v`, to the standard output stream using printf.
 */
void ll_printVec(llvec v);

/**
 * Print out a matrix to the standard output stream using printf().
 */
void ll_printMat(llmat m);

/**
 * Returns the matrix representation of vector `v`.
 */
llmat ll_vecToMat(llvec v);

/**
 * Returns the vector representation of matrix `m`.
 */
llvec ll_matToVec(llmat M);

/**
 * Returns the vector `v` multiplied by matrix `M`.
 */
llvec ll_vecDotMat(llvec v, llmat M);

/**
 * Returns an orthographic projection matrix. `left` `right` `bottom` `top` `near` `far` define the clipping planes
 */
llmat ll_ortho(float left, float right, float bottom, float top, float near, float far);

/**
 * Returns a perspective projection matrix. `fov`(in radians) `near` `far` define the clipping planes
 */
llmat ll_persp(float fov, float aspect, float near, float far);

#endif /* LL_UTIL_H */
