#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Sift-down operation for heap
 * @array: Array of integers
 * @size: Size of array
 * @start: Root index
 * @end: Last index
 */
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swap;

	root = start;
	while ((child = root * 2 + 1) <= end)
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
 * heap_sort - Sort an array using Heap sort
 * @array: Array of integers
 * @size: Size of array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t start, end;

	if (!array || size < 2)
		return;

	for (start = (size - 2) / 2; start >= 0; start--)
		sift_down(array, size, start, size - 1);

	for (end = size - 1; end > 0; end--)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
