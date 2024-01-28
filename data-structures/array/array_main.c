#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "array.c"
#include "../../algorithms/sorting/insertion_sort.c"

static void test_insertion_sort() {
    const int size = rand() % 300;

    int_array* array = new_int_array(size);

    for (int i = 0; i < size; i++) {
        set_value(array, i, (rand() % 1000) - 500);
    }

    insertion_sort(array->array, array->size);

    for (int i = 0; i < size - 1; ++i) {
        assert(array->array[i] <= array->array[i + 1]);
    }

    free(array->array);
    free(array);
}


int main() {
    srand(time(NULL));
    test_insertion_sort();
}