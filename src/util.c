#include <math.h>

#include "util.h"

llmat ll_rotationMat(float x, float y, float z)
{
    float cosx = cosf(x);
    float cosy = cosf(y);
    float cosz = cosf(z);
    float sinx = sinf(x);
    float siny = sinf(y);
    float sinz = sinf(z);

    llmat out = ll_mat(3, 3,
        cosx * cosy * cosz - sinx * sinz, -cosx * cosy * sinz - sinx * cosz, cosx * siny,
        sinx * cosy * cosz + cosx * sinz, -sinx * cosy * sinz + cosx * cosz, sinx * siny,
        -siny * cosz, siny * sinz, cosy);

    return out;
}

llmat ll_rotateMat(llmat m, float x, float y, float z)
{
    llmat R = ll_rotationMat(x, y, z);
    return ll_dotMat(m, R);
}
