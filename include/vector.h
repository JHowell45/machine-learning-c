#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    size_t length;
    size_t capacity;
    double **items;
} vector_t;

vector_t *newVec(size_t capacity);

void vectorPush(vector_t *vec, double item);

void vectorInsert(vector_t *vec, double item, size_t index);

void vectorPop(vector_t *vec);

void vectorRemove(vector_t *vec, size_t index);

void freeVector(vector_t *vec);

#endif