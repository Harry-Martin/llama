#include "vec.h"
#include <stdio.h>

int main()
{
    llvec a = ll_vec(2.0f, 3.0f, 4.0f);
    llvec b = ll_vec(5.0f, 6.0f, 7.0f);
    ll_printVec(ll_crossVec(a, b));
    return 0;
}
