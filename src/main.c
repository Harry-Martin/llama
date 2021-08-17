#include <stdio.h>
#include <string.h>

#include "vec.h"

int main()
{
    vec v = vector(1.0f, 2.0f, -3.0f);
    vec v1 = vector(1.0f, 2.0f, 3.0f);
    vec v2 = add(v, v1);
    print(&v2);
    return 0;
}
