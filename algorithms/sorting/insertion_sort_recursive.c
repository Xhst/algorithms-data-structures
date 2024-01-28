void insertion_sort_recursive(int* array, int size) {
    if (size <= 0) return;

    insertion_sort_recursive(array, size - 1);
    
    // value of the current element.
    int value = array[size - 1];
    
    int j = size - 2;

    // move to the right by one position all elements greater than the current value.
    while (j >= 0 && array[j] > value) {
        array[j + 1] = array[j];
        j = j - 1;
    }

    // insert the value in the right position.
    array[j + 1] = value;
    
}