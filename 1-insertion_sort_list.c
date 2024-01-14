/*#include "sort.h"
#include <stdio.h>

**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Pointer to the head of the linked list
 *
void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    listint_t *curr, *prev, *temp;

    curr = (*list)->next;

    while (curr)
    {
        temp = curr;

        while (temp->prev && temp->n < temp->prev->n)
        {
            prev = temp->prev;

            if (temp->next)
                temp->next->prev = prev;
            prev->next = temp->next;
            temp->next = prev;
            temp->prev = prev->prev;
            prev->prev = temp;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
        }

        curr = curr->next;
    }
}*/

#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: double pointer to the head of the list
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
        prev = curr->prev;

        while (prev != NULL && temp->n < prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = prev;

            prev->next = temp->next;
            temp->next = prev;
            temp->prev = prev->prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;

            prev->prev = temp;

            if (temp->prev == NULL)
                *list = temp;

            print_list(*list);
            prev = temp->prev;
        }

        curr = curr->next;
    }
}
