#include <stdio.h>

#include "vector.h"

int main(void) {
    vector_t *vec = newVec(3);
    vectorPush(vec, 5);
    if (vec->length == 1) {
        return 0;
    }
    return -1;
}