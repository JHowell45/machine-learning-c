#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "matrix.h"

matrix_t *newMatrix(size_t rows, size_t columns, double *data) {
    printf("data: %lf\n", data[3]);
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->items = calloc(matrix->columns, calloc(matrix->rows, sizeof(double)));
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
            matrix->items[y][x] = data[(x + 1) * y];
        }
    }
    return matrix;
}

void matrixPrint(matrix_t *matrix) {
    for (int x = 0; x < matrix->columns; x++) {
        for (int y = 0; y < matrix->rows; y++) {
            printf("%lf, ", matrix->items[y][x]);
        }
        printf("\n");
    }
}

void freeMatrix(matrix_t *matrix) {
    for (int x = 0; x < matrix->columns; x++) {
        free(matrix->items[x]);
    }
    free(matrix->items);
    free(matrix);
}

