#include <float.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"

llmat ll_allocateMat(unsigned int rows, unsigned int columns)
{
    llmat m;

    m.rows = rows;
    m.columns = columns;

    m.elements = (float**)malloc(rows * sizeof(float*));
    for (unsigned int i = 0; i < rows; i++)
    {
        m.elements[i] = (float*)malloc(columns * sizeof(float));
    }

    return m;
}

void ll_freeMat(llmat m)
{
    for (unsigned int i = 0; i < m.rows; i++)
    {
        free(m.elements[i]);
    }
    free(m.elements);
}

void ll_printMat(llmat m)
{
    for (unsigned int i = 0; i < m.rows; i++)
    {
        printf("| ");
        for (unsigned int j = 0; j < m.columns; j++)
        {
            printf("%6.*f ", 2, m.elements[i][j]);
        }
        printf("| \n");
    }
}

llmat ll_defaultMat(unsigned int rows, unsigned int columns, float defaultValue)
{
    llmat m = ll_allocateMat(rows, columns);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            m.elements[i][j] = defaultValue;
        }
    }

    return m;
}

llmat ll_matrix(unsigned int rows, unsigned int columns, ...)
{
    llmat m = ll_allocateMat(rows, columns);
    va_list args;

    va_start(args, columns);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            float value = va_arg(args, double);
            m.elements[i][j] = value;
        }
    }
    va_end(args);

    return m;
}

llmat ll_identityMat(unsigned int dimension)
{
    llmat m = ll_allocateMat(dimension, dimension);

    for (unsigned int i = 0; i < dimension; i++)
    {
        for (unsigned int j = 0; j < dimension; j++)
        {
            if (i == j)
            {
                m.elements[i][j] = 1.0f;
            }
            else
            {
                m.elements[i][j] = 0.0f;
            }
        }
    }

    return m;
}

llmat ll_copyMat(llmat m)
{
    llmat copy = ll_allocateMat(m.rows, m.columns);

    copy.rows = m.rows;
    copy.columns = m.columns;

    for (unsigned int i = 0; i < m.rows; i++)
    {
        memcpy(copy.elements[i], m.elements[i], m.columns);
    }

    return copy;
}

bool ll_sameDimMat(llmat A, llmat B)
{
    return A.rows == B.rows && A.columns == B.columns;
}

bool ll_equalMat(llmat A, llmat B)
{
    if (ll_sameDimMat(A, B))
    {
        for (unsigned int i = 0; i < A.rows; i++)
        {
            for (unsigned int j = 0; j < A.columns; j++)
            {
                if (A.elements[i][j] != B.elements[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

llmat ll_addMat(llmat A, llmat B)
{
    if (ll_sameDimMat(A, B) == false)
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_allocateMat(A.rows, A.columns);

    for (unsigned int i = 0; i < out.rows; i++)
    {
        for (unsigned int j = 0; j < out.columns; j++)
        {
            out.elements[i][j] = A.elements[i][j] + B.elements[i][j];
        }
    }

    return out;
}

llmat ll_subMat(llmat A, llmat B)
{
    if (ll_sameDimMat(A, B) == false)
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_allocateMat(A.rows, A.columns);

    for (unsigned int i = 0; i < out.rows; i++)
    {
        for (unsigned int j = 0; j < out.columns; j++)
        {
            out.elements[i][j] = A.elements[i][j] - B.elements[i][j];
        }
    }

    return out;
}

llmat ll_mulMat(llmat A, llmat B)
{
    if (ll_sameDimMat(A, B) == false)
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_allocateMat(A.rows, A.columns);

    for (unsigned int i = 0; i < out.rows; i++)
    {
        for (unsigned int j = 0; j < out.columns; j++)
        {
            out.elements[i][j] = A.elements[i][j] * B.elements[i][j];
        }
    }

    return out;
}

llmat ll_divMat(llmat A, llmat B)
{
    if (ll_sameDimMat(A, B) == false)
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_allocateMat(A.rows, A.columns);

    for (unsigned int i = 0; i < out.rows; i++)
    {
        for (unsigned int j = 0; j < out.columns; j++)
        {
            out.elements[i][j] = A.elements[i][j] / B.elements[i][j];
        }
    }

    return out;
}

llmat ll_dotMat(llmat A, llmat B)
{
    if (A.columns != B.rows)
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_defaultMat(A.rows, B.columns, 0.0f);

    for (unsigned int j = 0; j < B.columns; j++)
    {
        for (unsigned int i = 0; i < A.rows; i++)
        {
            for (unsigned int k = 0; k < A.columns; k++)
            {
                out.elements[i][j] += A.elements[i][k] * B.elements[k][j];
            }
        }
    }
    return out;
}

llmat ll_transposeMat(llmat m)
{
    if (ll_equalMat(m, LL_MAT_UNDEFINED))
    {
        return m;
    }

    llmat out = ll_allocateMat(m.columns, m.rows);
    for (unsigned int i = 0; i < m.rows; i++)
    {
        for (unsigned int j = 0; j < m.columns; j++)
        {
            out.elements[j][i] = m.elements[i][j];
        }
    }
    return out;
}

llmat ll_newSubMat(llmat m, unsigned int mj)
{
    if (m.rows != m.columns) /*function only defined for square matrices*/
    {
        return LL_MAT_UNDEFINED;
    }

    llmat out = ll_allocateMat(m.rows - 1, m.columns - 1);

    for (unsigned int i = 1; i < m.rows; i++)
    {
        for (unsigned int j = 0; j < m.columns; j++)
        {
            if (j < mj)
            {
                out.elements[i - 1][j] = m.elements[i][j];
            }
            else
            {
                out.elements[i - 1][j] = m.elements[i][j + 1];
            }
        }
    }
    return out;
}

float ll_detMat(llmat m)
{
    if (m.rows != m.columns) /*function only defined for square matrices*/
    {
        return FLT_MAX; /*TODO(harry): come up with a more elegant way to fail*/
    }
    if (m.rows == 2)
    {
        return m.elements[0][0] * m.elements[1][1] - m.elements[0][1] * m.elements[1][0];
    }
    float det = 0;
    float sign = 1;
    for (unsigned int j = 0; j < m.columns; j++)
    {
        llmat subMatrix = ll_newSubMat(m, j);
        float subMatrix_det = ll_detMat(subMatrix);
        det += (sign * (m.elements[0][j] * subMatrix_det));
        sign *= -1;
    }
    return det;
}
