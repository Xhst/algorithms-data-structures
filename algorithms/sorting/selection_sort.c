void selection_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {

        int min_pos = i;

        for (int j = i + 1; j < size; j++) {
            if (array[min_pos] > array[j]) {
                min_pos = j;
            }
        }

        // swap positions
        if (min_pos != i) {
            int temp = *(array + i);
            *(array + i) = *array;
            *array = temp;
        }
    }
}