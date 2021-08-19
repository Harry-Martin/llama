#include "vec.h"
#include <stdio.h>

int main()
{
    llvec a = ll_vec(1.0f, 0.0f, 0.0f);
    llvec b = ll_vec(0.0f, 1.0f, 0.0f);
    llvec c = ll_vec(0.0f, 0.0f, 1.0f);
    float adotb = ll_dotVec(a, b);
    float adota = ll_dotVec(a, a);
    ll_printVec(&a);
    ll_printVec(&b);
    ll_printVec(&c);
    llvec d = ll_addVec(a, b);
    ll_printVec(&d);
    printf("%f\n", adota);
    return 0;
}
