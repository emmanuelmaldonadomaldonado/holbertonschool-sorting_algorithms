#include "sort.h"
#include <stdlib.h>  // Include the necessary header file

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size) {
    if (array == NULL || size <= 1) {
        return;
    }

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    /* Create a counting array with size (max + 1) and initialize to 0 */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL) {
        return; // Unable to allocate memory
    }

    for (int i = 0; i <= max; i++) {
        counting_array[i] = 0;
    }

    /* Populate the counting array with the occurrences of each element in the input array */
    for (size_t i = 0; i < size; i++) {
        counting_array[array[i]]++;
    }

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Update the original array using the counting array */
    size_t j = 0;
    for (int i = 0; i <= max; i++) {
        while (counting_array[i] > 0) {
            array[j++] = i;
            counting_array[i]--;
        }
    }

    /* Free the counting array */
    free(counting_array);
}
