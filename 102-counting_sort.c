#include "sort.h"
#include <stdlib.h>

/**
 * get_max_value - Find the maximum value in an array
 * @array: The array of integers
 * @size: Number of elements in array
 *
 * Return: The maximum value
 */
static int get_max_value(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * build_count_prefix_print - Build counting array, prefix sums, then print it
 * @array: The array of integers
 * @size: Number of elements in array
 * @count: Counting array (size k + 1)
 * @k: Maximum value in array
 */
static void build_count_prefix_print(int *array, size_t size, int *count, int k)
{
	size_t i;
	int j;

	for (i = 0; i < (size_t)(k + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (j = 1; j <= k; j++)
		count[j] += count[j - 1];

	print_array(count, (size_t)(k + 1));
}

/**
 * fill_output_and_copy - Fill output array (stable) then copy back to array
 * @array: The original array
 * @size: Number of elements
 * @count: Counting array with prefix sums
 * @output: Output array
 */
static void fill_output_and_copy(int *array, size_t size, int *count, int *output)
{
	ssize_t i;
	int v;
	size_t j;

	for (i = (ssize_t)size - 1; i >= 0; i--)
	{
		v = array[i];
		output[count[v] - 1] = v;
		count[v] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];
}

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array of integers
 * @size: Number of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int k;

	if (array == NULL || size < 2)
		return;

	k = get_max_value(array, size);

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	build_count_prefix_print(array, size, count, k);
	fill_output_and_copy(array, size, count, output);

	free(output);
	free(count);
}
