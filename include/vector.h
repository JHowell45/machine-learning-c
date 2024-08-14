#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    size_t length;
    double **items;
} vector_t;

vector_t *newVector(double items[], size_t length);

void freeVector(vector_t *vec);

#endif