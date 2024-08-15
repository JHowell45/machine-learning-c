#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct {
    size_t rows;
    size_t columns;
    double **items;
} matrix_t;

matrix_t *newMatrix(size_t columns, size_t rows, double *data);

void matrixPrint(matrix_t *matrix);

void freeMatrix(matrix_t *matrix);

#endif