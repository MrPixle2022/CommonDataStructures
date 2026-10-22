#include "stdint.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    int length;
    int capacity;
    long element_size;
    void* data;
} Vector;
#endif