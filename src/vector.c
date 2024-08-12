#include <stdlib.h>

#include "vector.h"

vector_space_t *newVecSpace(size_t capacity) {
    vector_space_t *space = malloc(sizeof(vector_space_t));
    space->index = 0;
    space->capacity = capacity;
    space->items = calloc(space->capacity, sizeof(double));
    return space;
}

void freeVecSpace(vector_space_t *space) {
    free(space->items);
    free(space);
}