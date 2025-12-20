#include "sort.h"

/**
 * swap_forward - Swaps a node with its next node (move node forward)
 * @list: Pointer to the head pointer
 * @node: Node to swap with its next
 */
static void swap_forward(listint_t **list, listint_t *node)
{
	listint_t *next;

	if (list == NULL || *list == NULL || node == NULL || node->next == NULL)
		return;

	next = node->next;

	node->next = next->next;
	if (next->next != NULL)
		next->next->prev = node;

	next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = next;
	else
		*list = next;

	next->next = node;
	node->prev = next;
}

/**
 * swap_backward - Swaps a node with its previous node (move node backward)
 * @list: Pointer to the head pointer
 * @node: Node to swap with its previous
 */
static void swap_backward(listint_t **list, listint_t *node)
{
	listint_t *prev;

	if (list == NULL || *list == NULL || node == NULL || node->prev == NULL)
		return;

	prev = node->prev;

	prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = prev;

	node->prev = prev->prev;
	if (prev->prev != NULL)
		prev->prev->next = node;
	else
		*list = node;

	node->next = prev;
	prev->prev = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *start, *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;

	do {
		swapped = 0;
		current = start;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_forward(list, current);
				print_list(*list);
				swapped = 1;
				continue;
			}
			current = current->next;
		}
		end = current;

		if (swapped == 0)
			break;

		swapped = 0;
		current = end;

		while (current->prev != start->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_backward(list, current);
				print_list(*list);
				swapped = 1;
				continue;
			}
			current = current->prev;
		}
		start = current;
	} while (swapped);
}
