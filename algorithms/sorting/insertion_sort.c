void insertion_sort(int* array, int size) {
    for (int i = 1; i < size; i++) {

        // value of the current element.
        int value = array[i];
        
        int j = i - 1;

        // move to the right by one position all elements greater than the current value.
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        // insert the value in the right position.
        array[j + 1] = value;
    }
}