#include "mat.h"
#include "vec.h"
#include <stdio.h>

int main()
{
    llmat A = ll_matrix(1, 2,
        1.0f, 2.0f);

    llmat B = ll_matrix(2, 2,
        1.0f, 2.0f,
        3.0f, 4.0f);

    llmat C = ll_dotMat(A, B);

    ll_printMat(B);
    printf("\n");
    ll_printMat(ll_transposeMat(B));

    return 0;
}
