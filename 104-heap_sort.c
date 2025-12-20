#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
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
 * sift_down - Sift-down operation for heap sort
 * @array: Array of integers
 * @size: Size of the array
 * @start: Start index
 * @end: End index
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swap_idx;

	root = start;
	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap_ints(array + root, array + swap_idx);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sort an array using heap sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	start = size / 2;
	while (start > 0)
	{
		start--;
		sift_down(array, size, start, size - 1);
	}

	end = size - 1;
	while (end > 0)
	{
		swap_ints(array, array + end);
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
		end--;
	}
}
