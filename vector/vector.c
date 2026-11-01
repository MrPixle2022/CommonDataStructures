#include "vector.h"
#include <string.h>
#include <stdlib.h>


/// @brief resizes the vector to the given new capacity
/// @param vec the target vector object
/// @param new_capacity the new capacity, if is `0` will return `1`
/// @return returns `1` for errors, and `0` for success
int _resize_vector(Vector* vec, size_t new_capacity){
    //if vector is null or if new_capacity is 0 or data is null or element size is 0
    if(vec == NULL || new_capacity == 0 || vec ->_element_size == 0 || vec->_data == NULL) return 1;

    //actual reallocation
    void* temp = realloc(vec->_data, vec->_element_size * new_capacity);
    if(temp == NULL) return 1;
    vec->_data = temp;
    //reassign capacity and length
    vec->capacity = new_capacity;
    //if the new_capacity is less than the length (the vector shrinks)
    vec ->length = vec->length > new_capacity? new_capacity : vec-> length;
    return 0;
}

/// @brief release the vector
/// @param vec the target vector pointer
void _free_vector(Vector* vec){
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
    //allocates the data for the vector
    void* data = malloc(element_size * capacity);
    //if allocation fails, drop all
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

int vector_push(Vector* vec, void* element){
    //if invalid vector, element or in-compatible size
    if(vec == NULL || element == NULL) return 1;

    //if vector is max size, resize it
    if(vec->length >= vec->capacity){
        //resizing the vector to double its capacity
        if(_resize_vector(vec, vec->capacity * 2) != 0) return 1;
    }

    //moving to the end of the vector
    void* target = (char*)vec->_data + (vec->length * vec->_element_size);
    //copying the element to the target address
    memcpy(target, element, vec->_element_size);
    //incrementing the length
    vec->length++;
    return 0;
}

void* vector_pop(Vector* vec){
    //basic validator
    if(vec == NULL || vec->_data == NULL || vec->length == 0) return NULL;

    //clearing the element
    void *element = (char*)vec->_data + ((vec->length - 1) * vec->_element_size);
    //decreasing the length
    vec->length--;
    return element;
}

void* vector_at(Vector* vec, int index){
    if(vec == NULL || vec->_data == NULL || index > vec->length) return NULL;

    int targetIndex = index >= 0 ? index : (int)vec->length + index; 

    void *element = (char*)vec->_data + (vec->_element_size * targetIndex);
    return element;
}

int vector_index(Vector* vec, void* target){
    if(vec == NULL || vec->_data == NULL || target == NULL) return -1;
    int index = -1;

    //searching through the elements
    for(int i = 0; i < vec->length; i++){
        //extract the element
        void* element = (char*)vec->_data + (vec->_element_size * i);
        //compare the non-null element
        if(memcmp(target, element, vec->_element_size) == 0) {
            index = i;
            break;
        };
    }
    return index;
}
