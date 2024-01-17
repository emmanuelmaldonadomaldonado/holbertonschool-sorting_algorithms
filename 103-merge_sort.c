#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of arr[]
 * @arr: The array containing the subarrays
 * @temp: Temporary array to store the merged result
 * @l: Index of the left subarray
 * @m: Index of the middle point
 * @r: Index of the right subarray
 */
void merge(int *arr, int *temp, size_t l, size_t m, size_t r)
{
    size_t i, j, k;

    printf("Merging...\n[left]: ");
    print_array(arr + l, m - l);

    printf("[right]: ");
    print_array(arr + m, r - m);

    i = l;
    j = m;
    k = 0;

    while (i < m && j < r)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < m)
        temp[k++] = arr[i++];

    while (j < r)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[l + i] = temp[i];

    printf("[Done]: ");
    print_array(temp, k);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @arr: The array to be sorted
 * @temp: Temporary array to store the merged result
 * @l: Index of the left subarray
 * @r: Index of the right subarray
 */
void merge_sort_recursive(int *arr, int *temp, size_t l, size_t r)
{
    size_t m;

    if (r - l > 1)
    {
        m = l + (r - l) / 2;

        merge_sort_recursive(arr, temp, l, m);
        merge_sort_recursive(arr, temp, m, r);

        merge(arr, temp, l, m, r);
    }
}

/**
 * merge_sort - Sorts an array of integers using merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}
