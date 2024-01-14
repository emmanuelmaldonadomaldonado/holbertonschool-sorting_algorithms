#include "sort.h"
#include <stddef.h>

/**
 * quick_sort_recursive - Recursive helper function for quick_sort
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, temp;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i + 1);
}
