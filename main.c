#include <stdio.h>
#include "vector/vector.h"

typedef struct Element {
    int value;
} Element;

int main(int argc, char const *argv[])
{
    Vector* vec = vector_new(10, sizeof(Element));
    //test push
    for (int i = 0; i < 10; i++)
    {
        Element elem = {.value = i};
        vector_push(vec, (void*)&elem);
        printf("Pushed element with value: %d\n", elem.value);
    }

    printf(vec->_data == NULL ? "Vector data is NULL\n" : "Vector data is not NULL\n");
    printf("Vector length: %zu\n", vec->length);
    
    // //test access
    // Element* elem = (Element*)vector_at(vec, -1); //should return Element with value 10
    // printf("Value: %d\n", elem->value);

    // //test resize
    // vector_push(vec, &(Element){.value = 11});
    // printf("New length: %zu\n", vec->length);

    // //index lookup:
    // int index = vector_index(vec, &(Element){.value = 5});
    // printf("Index of element with value 5: %d\n", index);
    return 0;
}
