#include "sort.h"

static void quick_sort_lomuto(int *array, size_t size, int low, int high);
static int lomuto_partition(int *array, size_t size, int low, int high);
static void swap_ints(int *a, int *b);

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 *              (Lomuto partition scheme, pivot is last element)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, size, 0, (int)size - 1);
}

/**
 * quick_sort_lomuto - recursive quick sort using lomuto partition
 * @array: array to sort
 * @size: size of array (for printing)
 * @low: start index
 * @high: end index
 */
static void quick_sort_lomuto(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, size, low, high);
		quick_sort_lomuto(array, size, low, p - 1);
		quick_sort_lomuto(array, size, p + 1, high);
	}
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: array to partition
 * @size: size of array (for printing)
 * @low: start index
 * @high: end index (pivot = array[high])
 *
 * Return: pivot final index
 */
static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap_ints - swaps two integers
 * @a: first int
 * @b: second int
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
