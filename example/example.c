#include <math.h>
#include <stdio.h>

#include "../include/llama.h"
#include "../include/util.h"

int main()
{
    llmat proj = ll_persp(RADIANS(90.0f), 1.0f, 1.0f, 4.0f);
    llvec p;
    for (float i = 0.0f; i > -4.0f; i -= 0.4f)
    {
        p = ll_vec(50.0f, 50.0f, i, 1.0f);
        llvec p_proj = ll_vecDotMat(p, proj);
        /*ll_printVec(p_proj);*/
        ll_printVec(ll_divVec(p_proj,
                    ll_defaultVec(4, p_proj.components[3])));
    }

    return 0;
}
