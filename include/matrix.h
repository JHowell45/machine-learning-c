#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

#include "vector.h"

typedef struct {
    size_t rows;
    size_t columns;
    vector_t **items;
} matrix_t;

matrix_t *newMatrix(size_t rows, size_t columns);

void matrixPrint(matrix_t *matrix);

void freeMatrix(matrix_t *matrix);

#endif