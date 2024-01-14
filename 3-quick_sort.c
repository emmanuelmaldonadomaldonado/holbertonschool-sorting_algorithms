#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr, *prev, *temp;

    curr = (*list)->next;

    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            prev = temp->prev;  /* Update prev after swapping */
            prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = prev;
            temp->prev = prev->prev;
            temp->next = prev;
            prev->prev = temp;

            if (temp->prev == NULL)
                *list = temp; /* Update head if temp is new head */
            else
                temp->prev->next = temp; /* Update next of temp's prev */
            print_list(*list);
        }
    }
}
