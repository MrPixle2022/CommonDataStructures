#include "stddef.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    size_t length;
    size_t capacity;
    size_t _element_size;
    void* _data;
} Vector;

/// @brief creates a new vector object
/// @param capacity the maximum number of elements that can be stored before needing to resize
/// @param element_size the size of each individual element, fixed for all, and cannot be changed midway
/// @return a pointer to the vector object, or `NULL` on failure
Vector* new_vector(size_t capacity, size_t element_size);

#endif