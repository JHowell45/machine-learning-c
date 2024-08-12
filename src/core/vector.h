#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    size_t index;
    size_t capacity;
    double **items;
} vector_t;

vector_t *newVec(size_t capacity);

#endif