#include <math.h>
#include <stdio.h>

#include "llama.h"
#include "util.h"

int main()
{
    llvec r = ll_vec(0.0f, RADIANS(90), RADIANS(90));
    llvec p = ll_vec(0.0f, 1.0f, 0.0f, 1.0f);
    
    p = ll_vecRotateVec(p, r);
    
    ll_printVec(p);
    
    return 0;
}
