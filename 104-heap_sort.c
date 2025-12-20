#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Maintains the max heap property
 * @array: Array of integers
 * @size: Size of the array
 * @start: Root index
 * @end: Last index
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;
	size_t swap;

	while ((child = 2 * root + 1) <= end)
	{
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		swap_ints(&array[root], &array[swap]);
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array using heap sort
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t start;
	size_t end;

	if (!array || size < 2)
		return;

	start = (size / 2) - 1;
	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}

	end = size - 1;
	while (end > 0)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
