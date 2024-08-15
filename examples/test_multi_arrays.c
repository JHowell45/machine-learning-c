#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#define ARRAY_2D_COLS 4
#define ARRAY_2D_ROWS 3


int main(void) {
    double data[ARRAY_2D_ROWS][ARRAY_2D_COLS] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    for (int y = 0; y < ARRAY_2D_ROWS; y++) {
        for (int x = 0; x < ARRAY_2D_COLS; x++) {
            printf("%lf, ", data[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    matrix_t *matrix = newMatrix(ARRAY_2D_ROWS, ARRAY_2D_COLS, data);
    matrixPrint(matrix);
    freeMatrix(matrix);
    return 0;
}