#include "sort.h"

/**
 * swap_forward - Swap a node with its next node
 * @list: Pointer to head pointer
 * @node: Node to swap forward
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
 * @list: Pointer to head pointer
 * @node: Node to swap backward
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
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Pointer to head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		current = start;

		/* Forward pass */
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

		/* Backward pass */
		while (current->prev != NULL && current != start)
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
	}
}
