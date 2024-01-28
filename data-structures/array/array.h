#ifndef __ARRAY_H__
#define __ARRAY_H__

#define SUCCESS 1
#define ERROR 0

typedef struct int_array {
    int* array;
    int size;
} int_array;

/**
 * Returns reference to an empty int array.
 */
int_array* new_int_array(int size);

/**
 * Returns the size of the array.
 */ 
int size(struct int_array* array);

/**
 * Update the value in the array at the given position.
 */
int set_value(struct int_array* array, int position, int value);


#endif