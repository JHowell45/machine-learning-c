#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    size_t index;
    size_t capacity;
    double **items;
} vector_space_t;

vector_space_t *newVecSpace(size_t capacity);

void *vectorSpacePush(vector_space_t *vec, double item);

void freeVecSpace(vector_space_t *space);

#endif