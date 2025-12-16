#include "sort.h"

/**
 * swap_with_prev - Swaps a node with its previous node in a doubly linked list
 * @list: Pointer to the head pointer of the list
 * @node: The node to move backward (swap with its prev)
 */
static void swap_with_prev(listint_t **list, listint_t *node)
{
	listint_t *prev, *next;

	if (list == NULL || *list == NULL || node == NULL || node->prev == NULL)
		return;

	prev = node->prev;
	next = node->next;

	/* Link prev->prev to node */
	if (prev->prev != NULL)
		prev->prev->next = node;
	else
		*list = node;

	node->prev = prev->prev;

	/* Link node to prev */
	node->next = prev;
	prev->prev = node;

	/* Link prev to next */
	prev->next = next;
	if (next != NULL)
		next->prev = prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Pointer to the head pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_with_prev(list, current);
			print_list(*list);
		}

		current = next;
	}
}
