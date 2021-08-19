#include "vec.h"
#include <stdio.h>

int main()
{
    llvec a = ll_vec(1.0f, 0.0f);
    llvec b = ll_vec(0.0f, 1.0f);
    float theta = ll_angleVec(a, b);
    LOGF(DEGREES(theta));
    return 0;
}
