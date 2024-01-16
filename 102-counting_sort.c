#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize counting_array with zeros */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;
    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count occurrences of each element in the array */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Update counting_array to hold the cumulative count */
    for (int i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Create a temporary array to hold the sorted values */
    int *temp_array = malloc(size * sizeof(int));
    if (temp_array == NULL)
    {
        free(counting_array);
        return;
    }

    /* Build the sorted array using counting_array */
    for (int i = size - 1; i >= 0; i--)
    {
        temp_array[--counting_array[array[i]]] = array[i];
    }

    /* Copy the sorted array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = temp_array[i];

    /* Print the sorted array */
    print_array(array, size);

    /* Free the allocated memory */
    free(counting_array);
    free(temp_array);
}
