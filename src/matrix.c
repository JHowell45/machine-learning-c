#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

matrix_t *newMatrix(size_t rows, size_t columns, double *data) {
    printf("ROWS: %zu\n", rows);
    printf("COLUMNS: %zu\n", columns);
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->items = calloc(matrix->rows, sizeof(double *));
    for (int y = 0; y < matrix->rows; y++) {
        matrix->items[y] = calloc(matrix->columns, sizeof(double));
        for (int x = 0; x < matrix->columns; x++) {
            size_t index = (y * matrix->rows + y) + x;
            printf("Column: %zu, Row: %zu || Index: %d\n", y, x, index);
            matrix->items[y][x] = data[index];
        }
    }
    return matrix;
}

void matrixPrint(matrix_t *matrix) {
    for (int y = 0; y < matrix->rows; y++) {
        printf("[");
        for (int x = 0; x < matrix->columns; x++) {
            printf("%lf, ", matrix->items[y][x]);
        }
        printf("]\n");
    }
    printf("\n");
}

void freeMatrix(matrix_t *matrix) {
    for (int x = 0; x < matrix->columns; x++) {
        free(matrix->items[x]);
    }
    free(matrix->items);
    free(matrix);
}

