#include "sort.h"

/**
 * swap_forward - Swap a node with its next node
 * @list: Pointer to the head pointer
 * @node: Node to move forward
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
 * swap_backward - Swap a node with its previous node
 * @list: Pointer to the head pointer
 * @node: Node to move backward
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
 * cocktail_sort_list - Sort a doubly linked list using Cocktail Shaker sort
 * @list: Pointer to the head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped, swapped_fwd, swapped_bwd;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while ((*list)->prev != NULL)
		*list = (*list)->prev;

	start = *list;
	end = NULL;

	do {
		swapped_fwd = 0;
		current = start;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_forward(list, current);
				print_list(*list);
				swapped_fwd = 1;
				continue;
			}
			current = current->next;
		}
		end = current;

		swapped_bwd = 0;

		while (current->prev != NULL && current != start)
		{
			if (current->n < current->prev->n)
			{
				swap_backward(list, current);
				print_list(*list);
				swapped_bwd = 1;
				continue;
			}
			current = current->prev;
		}
		start = current;

		swapped = swapped_fwd || swapped_bwd;
	} while (swapped);
}
