#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i;
    int max = array[0];
    int *counting_array;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    counting_array = (int *)malloc((max + 1) * sizeof(int));

    if (counting_array == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    for (i = 0; i <= (size_t)max; i++)
    {
        while (counting_array[i] > 0)
        {
            printf("%lu", i);
            if (--counting_array[i] > 0)
                printf(", ");
        }
    }

    printf("\n");

    free(counting_array);
}
