#include "mat.h"
#include "vec.h"
#include <stdio.h>

int main()
{
    llmat A = ll_matrix(3, 3,
        3.0f, 0.0f, 2.0f,
        2.0f, 0.0f, -2.0f,
        0.0f, 1.0f, 1.0f);

    ll_printMat(ll_minorMat(A));

    return 0;
}
