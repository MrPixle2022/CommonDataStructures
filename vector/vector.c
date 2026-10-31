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
    vec->  _data = data;
    vec ->  length = 0;
    vec ->  capacity = capacity;
    vec ->  _element_size = element_size;
    return vec;
}