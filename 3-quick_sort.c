#include "sort.h"

/**
 * swap_and_print - Swap 2 elements and print ONLY if swap changes the array
 * @array: array
 * @i: first index
 * @j: second index
 * @size: array size
 */
static void swap_and_print(int *array, ssize_t i, ssize_t j, size_t size)
{
	int tmp;

	if (i == j)
		return;
	if (array[i] == array[j])
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - Lomuto partition (pivot = last element)
 * @array: array
 * @low: low index
 * @high: high index
 * @size: array size
 *
 * Return: pivot final index
 */
static ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_and_print(array, i, j, size);
		}
	}

	/* swap pivot into place ONLY if it actually changes something */
	swap_and_print(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quick_sort_rec - recursion
 * @array: array
 * @low: low index
 * @high: high index
 * @size: array size
 */
static void quick_sort_rec(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Quick sort using Lomuto partition scheme
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, (ssize_t)size - 1, size);
}
