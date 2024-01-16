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

    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
    {
        if ((size_t)array[i] > (size_t)max)
            max = array[i];
    }

    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    print_array(counting_array, max + 1);

    int *temp_array = malloc(size * sizeof(int));
    if (temp_array == NULL)
    {
        free(counting_array);
        return;
    }

    for (i = size; i > 0; i--)
    {
        temp_array[--counting_array[array[i - 1]]] = array[i - 1];
    }

    for (i = 0; i < size; i++)
        array[i] = temp_array[i];

    print_array(array, size);

    free(counting_array);
    free(temp_array);
}
