#include "vec.h"
#include <stdio.h>

int main()
{
    llvec a = ll_vec(77.0f, 0.0f, 0.0f);
    llvec b = ll_normVec(a);
    ll_printVec(&b);
    return 0;
}
