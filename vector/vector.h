#include <stddef.h>

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
Vector* vector_new(size_t capacity, size_t element_size);

/// @brief pushes an element to the end of the vector, fails if vector is invalid, internal data is invalid, target size is not the same as the element size of the vector's elements or if resizing fails
/// @param vec the target vector object
/// @param element the element to be pushed, must be a pointer to the element
/// @return `0` for success, `1` for failure
int vector_push(Vector* vec, void* element);

/// @brief removes the last element in a vector, fails if vector is invalid, internal data is invalid, target element's size is not the same as the size of the vector's elements
/// @param vec the vector object
/// @param out_element target element
/// @return the element popped, or `NULL`
void* vector_pop(Vector* vec);

/// @brief retrieves the element in the vector at the given index
/// @param vec the vector
/// @param index the target index, can use negative values to target elements from the end
/// @return the element at that index of `NULL`
void* vector_at(Vector* vec, int index);

/// @brief searches for the index of the first occurrence of the target in the vector
/// @param vec the vector
/// @param target the target element
/// @return the index of the first instance, or `-1` on failure
int vector_index(Vector* vec, void* target);
#endif