#include "mat.h"
#include "vec.h"
#include <stdio.h>

int main()
{
    llmat A = ll_matrix(2, 3,
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f);

    llmat B = ll_matrix(3, 2,
        7.0f, 8.0f,
        9.0f, 10.0f,
        11.0f, 12.0f);

    llmat C = ll_mulMat(A, B);
    ll_printMat(C);

    return 0;
}
