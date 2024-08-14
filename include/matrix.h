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

void matrixInsertColumn(matrix_t *matrix, vector_t *column, size_t columnIndex);

void freeMatrix(matrix_t *matrix);

#endif