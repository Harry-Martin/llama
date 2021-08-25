#include "mat.h"
#include "vec.h"
#include <stdio.h>

int main()
{
    llmat A = ll_matrix(4, 4,
        3.0f, 2.0f, -1.0f, 4.0f,
        2.0f, 1.0f, 5.0f, 7.0f,
        0.0f, 5.0f, 2.0f, -6.0f,
        -1.0f, 2.0f, 1.0f, 0.0f);

    ll_printMat(ll_newSubMat(A, 0, 0));
    printf("\n");
    ll_printMat(ll_newSubMat(A, 0, 1));
    printf("\n");
    ll_printMat(ll_newSubMat(A, 0, 2));

    LOGF(ll_detMat(A));
    return 0;
}
