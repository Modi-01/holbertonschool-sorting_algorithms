#include "sort.h"

/**
 * swap_adjacent - Swap a node with its next node in a doubly linked list
 * @list: Pointer to the head pointer of the list
 * @left: Pointer to the left node (must have a next node)
 *
 * Return: Pointer to the node that ends up in the left position after swap
 */
static listint_t *swap_adjacent(listint_t **list, listint_t *left)
{
	listint_t *right;

	if (list == NULL || *list == NULL || left == NULL || left->next == NULL)
		return (NULL);

	right = left->next;

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

	return (right);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using Cocktail shaker sort
 * @list: Pointer to the head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *end = NULL, *start = NULL;
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;

	while (swapped)
	{
		swapped = 0;
		curr = start;

		/* Forward pass */
		while (curr->next != end)
		{
			if (curr->n > curr->next->n)
			{
				swap_adjacent(list, curr);
				print_list(*list);
				swapped = 1;

				/*
				 * After swapping curr with curr->next,
				 * curr is now after the smaller node.
				 * Keep curr where it is (do not advance) to compare again.
				 */
				continue;
			}
			curr = curr->next;
		}
		end = curr;

		if (!swapped)
			break;

		swapped = 0;

		/* Backward pass */
		while (curr->prev != start->prev)
		{
			if (curr->prev != NULL && curr->prev->n > curr->n)
			{
				/*
				 * To swap (curr->prev) with curr, pass curr->prev
				 */
				swap_adjacent(list, curr->prev);
				print_list(*list);
				swapped = 1;

				/*
				 * After swapping, curr moved one step left.
				 * Keep curr where it is to continue moving backward.
				 */
				continue;
			}
			curr = curr->prev;
		}
		start = curr;
	}
}
