#include <stdlib.h>

#include "vector.h"

vector_t *newVector(double items[], size_t length) {
    vector_t *vec = malloc(sizeof(vector_t));
    vec->length = length;
    vec->items = calloc(vec->length, sizeof(double));
    for (int i = 0; i < vec->length; i++) {
        vec->items[i] = &items[i];
    }
    return vec;
}

void freeVector(vector_t *vec) {

}