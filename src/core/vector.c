#include <stdlib.h>

#include "vector.h"

vector_t *newVec(size_t capacity) {
    vector_t *vec = malloc(sizeof(vector_t));
    vec->index = 0;
    vec->capacity = capacity;
    vec->items = calloc(vec->capacity, sizeof(double));
    return vec;
}