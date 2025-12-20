#include "sort.h"

/**
 * swap_adjacent - Swap two adjacent nodes in a doubly linked list
 * @list: Pointer to the head pointer of the list
 * @left: The left node (must be right->prev)
 * @right: The right node (must be left->next)
 */
static void swap_adjacent(listint_t **list, listint_t *left, listint_t *right)
{
	if (list == NULL || *list == NULL || left == NULL || right == NULL)
		return;

	if (left->next != right || right->prev != left)
		return;

	left->next = right->next;
	if (right->next != NULL)
		right->next->prev = left;

	right->prev = left->prev;
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sort a doubly linked list using Cocktail Shaker sort
 * @list: Pointer to the head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *start, *end, *start_prev;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while ((*list)->prev != NULL)
		*list = (*list)->prev;

	start = *list;
	end = NULL;

	while (1)
	{
		swapped = 0;
		cur = start;

		while (cur->next != end)
		{
			if (cur->n > cur->next->n)
			{
				swap_adjacent(list, cur, cur->next);
				print_list(*list);
				swapped = 1;
				if (cur->prev != NULL)
					cur = cur->prev;
				continue;
			}
			cur = cur->next;
		}
		end = cur;

		if (!swapped)
			break;

		swapped = 0;
		start_prev = start->prev;
		cur = end;

		while (cur->prev != start_prev)
		{
			if (cur->prev->n > cur->n)
			{
				swap_adjacent(list, cur->prev, cur);
				print_list(*list);
				swapped = 1;
				if (cur->next != NULL)
					cur = cur->next;
				continue;
			}
			cur = cur->prev;
		}
		start = cur;

		if (!swapped)
			break;
	}
}
