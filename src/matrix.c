#include <stdlib.h>

#include "vector.h"
#include "matrix.h"

matrix_t *newMatrix(size_t rows, size_t columns) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->columns = columns;
    matrix->rows = rows;
    matrix->items = calloc(matrix->columns, sizeof(vector_t));
}

void matrixInsertColumn(matrix_t *matrix, vector_t *column, size_t columnIndex) {
    matrix->items[columnIndex] = column;
}

void freeMatrix(matrix_t *matrix) {
    for (int x = 0; x < matrix->columns; x++) {
        free(matrix->items[x]);
    }
    free(matrix);
}

