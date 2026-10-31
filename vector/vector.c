#include "vector.h"
#include <stdlib.h>

Vector* new_vector(size_t capacity, size_t element_size){
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
    vec ->length = 0;
    vec ->capacity = capacity;
    vec ->_element_size = element_size;
    return vec;
}

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