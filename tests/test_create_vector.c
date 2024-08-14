#include <stdio.h>

#include "vector.h"

int main(void) {
    // double **items = calloc(3, sizeof(double));
    const size_t ARRAY_LENGTH = 3;
    double items[] = {4.0, 2.7, 2.5};
    vector_t *vec = newVector(items, ARRAY_LENGTH);
    if (vec->length != ARRAY_LENGTH) {
        printf("The vector length of %zu != %zu\n", vec->length, ARRAY_LENGTH);
        return 1;
    }
    for (int i = 0; i < ARRAY_LENGTH; i ++) {
        double arrayItem = *vec->items[i];
        double actualItem = items[i];
        if (arrayItem != actualItem) {
            printf("The array value '%lf' != '%lf' at index: %d\n", arrayItem, actualItem, i);
            return 1;
        }
    }
    return 0;
}