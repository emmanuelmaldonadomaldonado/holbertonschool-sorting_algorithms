#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !*list || !(*list)->next)
        return;

    listint_t *curr, *prev, *temp;

    curr = (*list)->next;
    while (curr)
    {
        temp = curr;
        prev = curr->prev;
        curr = curr->next;

        while (prev && temp->n < prev->n)
        {
            if (temp->next)
                temp->next->prev = prev;

            if (prev->prev)
                prev->prev->next = temp;
            else
                *list = temp;

            temp->prev = prev->prev;
            prev->next = temp->next;
            temp->next = prev;
            prev->prev = temp;

            print_list(*list);

            prev = temp->prev;
        }
    }
}
