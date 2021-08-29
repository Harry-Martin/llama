#include <math.h>
#include <stdio.h>

#include "../include/llama.h"
#include "../include/util.h"

int main()
{
    llvec testv = ll_vec(1.0f, 2.0f, 3.0f, 4.0f, 5.0f);
    llmat testm = ll_mat(4, 5,
            1.0f,2.0f, 3.0f, 4.0f,
            1.0f,2.0f, 3.0f, 4.0f,
            1.0f,2.0f, 3.0f, 4.0f,
            1.0f,2.0f, 3.0f, 4.0f,
            1.0f,2.0f, 3.0f, 4.0f);
    float * data = ll_matToFloats(testm);
    for(unsigned int i = 0; i < testm.rows * testm.columns; i++)
    {
        LOGF(data[i]);
    }
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
