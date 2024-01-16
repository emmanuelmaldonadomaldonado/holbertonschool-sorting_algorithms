#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order using Cocktail Shaker sort
 * @list: Pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list) {
	int swapped;
	listint_t *start, *end, *current;

	if (list == NULL || *list == NULL)
		return;

	start = NULL;
	end = NULL;
	swapped = 1;

	while (swapped) {
		swapped = 0;
		current = *list;

		while (current->next != end) {
			if (current->n > current->next->n) {
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		end = current;

		while (current->prev != start) {
			if (current->n < current->prev->n) {
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
			else
				current = current->prev;
		}

		start = current;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}

