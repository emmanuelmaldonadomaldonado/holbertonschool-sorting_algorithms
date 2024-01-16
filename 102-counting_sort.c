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

    /* Update the array with sorted values from counting_array */
    size_t i = 0;
    for (int j = 0; j <= max; j++)
    {
        while (counting_array[j] > 0)
        {
            array[i++] = j;
            counting_array[j]--;
        }
    }

    /* Print the counting_array */
    printf("%d", counting_array[0]);
    for (int i = 1; i <= max; i++)
        printf(", %d", counting_array[i]);
    printf("\n");

    /* Free the counting_array */
    free(counting_array);
}
