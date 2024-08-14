#include <stdlib.h>

#include "vector.h"

vector_t *newVec(size_t capacity) {
    vector_t *vec = malloc(sizeof(vector_t));
    vec->length = 0;
    vec->capacity = capacity;
    vec->items = calloc(vec->capacity, sizeof(double));
    return vec;
}

void vectorIncreaseCapacity(vector_t *vec) {
    vec->capacity *= 2;
    realloc(vec->items, vec->capacity);
}

void vectorPush(vector_t *vec, double item) {
    if (vec->length >= vec->capacity - 1) {
        vectorIncreaseCapacity(vec);
    }
    vec->items[vec->length] = &item;
    vec->length++;
}

void vectorInsert(vector_t *vec, double item, size_t index) {
    if (vec->length >= vec->capacity - 1) {
        vectorIncreaseCapacity(vec);
    }
    for (int insertIndex = vec->length-1; insertIndex >= index; index--) {
        vec->items[index+1] = vec->items[index];
    }
    vec->items[index] = &item;
}

void vectorPop(vector_t *vec) {
    vec->length--;
}

void vectorRemove(vector_t *vec, size_t index) {

}

void freeVector(vector_t *vec) {

}