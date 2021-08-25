#include <math.h>
#include <stdio.h>

#include "llama.h"
#include "mat.h"
#include "vec.h"

int main()
{
    /* create a matrix */
    llmat A = ll_mat(3, 3, /* [3 x 3] matrix */
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f);

    llmat B = ll_mat(3, 2, /* [3 x 2] matrix */
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f);

    /* matrix multiplication */
    llmat AB = ll_dotMat(A, B);

    /* determinant */
    float A_det = ll_detMat(A);

    /* inverse */
    llmat A_inverse = ll_inverseMat(A);

    /* transpose */
    llmat B_transpose = ll_transposeMat(B);
    /* print matrix */
    ll_printMat(AB);
    LOGF(A_det);
    ll_printMat(A_inverse);
    ll_printMat(B_transpose);

    return 0;
}
