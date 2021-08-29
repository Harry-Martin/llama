#ifndef LLAMA_H
#define LLAMA_H

#define bool unsigned char
#define true 1
#define false 0

#define PI 3.14159265359

#define DEGREES(x) (x * (180.0f / PI))
#define RADIANS(x) (x * (PI / 180))
#define LOGF(x) (printf("%f\n", x))

/**
 * Macro to call ll_rotationMat with vector `v` instead of 3 floats.
 */
#define ll_rotationMatrix(v) ll_rotationMat(v.components[0], v.components[1], v.components[2])

/**
 * Macro to call ll_rotateMat with vector `v` instead of 3 floats.
 */
#define ll_rotateMatrix(m, r) ll_rotateMat(m, r.components[0], r.components[1], r.components[2])

#endif
