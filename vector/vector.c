#include "vector.h"
#include <stdlib.h>

Vector* vector_new(size_t capacity, size_t element_size){
    //allocated vector
    Vector *vec = malloc(sizeof(Vector));
    if(vec == NULL) return NULL;

    //allocate data
    if(capacity == 0) capacity = 10;
    if(element_size == 0) {
        free(vec);
        return NULL;
    }
    void* data = malloc(element_size * capacity);
    if(data == NULL){
        free(vec);
        return NULL;
    }

    // final assigning
    vec->_data = data;
    vec->length = 0;
    vec->capacity = capacity;
    vec->_element_size = element_size;
    return vec;
}

/// @brief resizes the vector to the given new capacity
/// @param vec the target vector object
/// @param new_capacity the new capacity, if is `0` will return `1`
/// @return returns `1` for errors, and `0` for success
static int _resize_vector(Vector* vec, size_t new_capacity){
    //if vector is null or if new_capacity is 0 or data is null or element size is 0
    if(vec == NULL || new_capacity == 0 || vec ->_element_size == 0 || vec->_data == NULL) return 1;

    //reassign capacity and length
    vec->capacity = new_capacity;
    //if the new_capacity is less than the length (the vector shrinks)
    vec ->length = vec -> length > new_capacity? new_capacity : vec-> length;
    //actual reallocation
    vec->_data = realloc(vec->_data, vec->_element_size * new_capacity);
    if(vec ->  _data == NULL) return 1;
    return 0;
}

/// @brief release the vector
/// @param vec the target vector pointer
static void _free_vector(Vector* vec){
    //if the vector is invalid
    if(vec == NULL) return;
    // if the data is valid clear it
    if(vec->_data != NULL){
        free(vec->_data);
        //just in case
        vec->_data = NULL;
    }
    free(vec);
    return;
}