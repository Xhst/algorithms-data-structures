#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int_array* new_int_array(int size) {
    int_array *array = (int_array*) malloc(sizeof(int_array));
    array->array = (int*) malloc(sizeof(int) * size);
    array->size = size;

    return array;
}


int size(int_array* array) {
    if (array == NULL) return 0;

    return array->size;
}


int set_value(int_array* array, int position, int value) {
    if (array == NULL || position < 0 || position > array->size) return ERROR;

    array->array[position] = value;
    
    return SUCCESS;
}