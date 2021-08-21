#include "mat.h"
#include "vec.h"
#include <stdio.h>

int main()
{
    llmat A = ll_matrix(2, 2,
        100.0f, 2.0f,
        3.0f, 4.0f);

    llmat B = ll_matrix(2, 2,
        5.0f, 6.0f,
        7.0f, 8.0f);

    llmat C = ll_divMat(A, B);

    ll_printMat(C);
    return 0;
}
