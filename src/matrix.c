#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "matrix.h"

matrix_t *newMatrix(size_t columns, size_t rows, double *data) {
    printf("data: %lf\n", data[3]);
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->items = calloc(matrix->columns, sizeof(double *));
    for (int y = 0; y < matrix->columns; y++) {
        matrix->items[y] = calloc(matrix->rows, sizeof(double));
        for (int x = 0; x < matrix->rows; x++) {
            size_t index = (y * matrix->columns + y) + x;
            printf("INDEX: %zu || X: %d, Y: %d, Y2: %zu\n", index, x, y, (y * matrix->columns + y));
            matrix->items[y][x] = data[index];
        }
    }
    return matrix;
}

void matrixPrint(matrix_t *matrix) {
    printf("HELLO");
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

