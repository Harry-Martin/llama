#include <math.h>
#include <stdio.h>

#include "llama.h"
#include "util.h"

int main()
{
    llmat proj = ll_persp(RADIANS(90.0f), 0.0f, 100.0f);
    llvec p;
    for (float i = 0.0f; i < 100.0f; i += 10.0f)
    {
        p = ll_vec(50.0f, 50.0f, i, 1.0f);
        llvec p_proj = ll_vecDotMat(p, proj);
        ll_printVec(ll_divVec(p_proj, ll_defaultVec(4, p_proj.components[3])));
    }

    return 0;
}
