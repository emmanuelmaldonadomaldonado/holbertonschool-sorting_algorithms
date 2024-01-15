#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;
    listint_t *prev, *temp;

    while (curr != NULL)
    {
        temp = curr;
        prev = curr->prev;

        while (prev != NULL && prev->n > temp->n)
        {
            prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = prev;

            temp->next = prev;
            temp->prev = prev->prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;
            print_list(*list);
            prev = temp->prev;
        }

        curr = curr->next;
    }
}
