#include "sort.h"

/**
 * swap_and_print - swaps two elements in array and prints after swap
 *                  but ONLY if indices differ and values differ
 * @array: array of integers
 * @i: first index
 * @j: second index
 * @size: size of array
 */
static void swap_and_print(int *array, int i, int j, size_t size)
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
 * lomuto_partition - partitions array using Lomuto scheme (pivot = last)
 * @array: array of integers
 * @low: low index
 * @high: high index (pivot position initially)
 * @size: size of array
 *
 * Return: partition index
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

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

	swap_and_print(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quick_sort_rec - recursive quick sort
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of array
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort (Lomuto)
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
