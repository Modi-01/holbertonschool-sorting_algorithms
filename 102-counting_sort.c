#include "sort.h"
#include <stdlib.h>

/**
 * get_max_value - finds the maximum value in an array
 * @array: array of integers
 * @size: number of elements in array
 *
 * Return: maximum value
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
 * build_count_array - builds the counting array (frequency)
 * @array: array of integers
 * @size: number of elements in array
 * @count: counting array
 * @k: maximum value in array
 */
static void build_count_array(int *array, size_t size, int *count, int k)
{
	size_t i;

	for (i = 0; i < (size_t)(k + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;
}

/**
 * prefix_sum_and_print - converts count array to prefix sums and prints it
 * @count: counting array
 * @k: maximum value in array
 */
static void prefix_sum_and_print(int *count, int k)
{
	int i;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, (size_t)(k + 1));
}

/**
 * build_output - builds the sorted output array using counting array
 * @array: input array
 * @size: number of elements
 * @count: counting array (prefix sums)
 * @output: output array
 */
static void build_output(int *array, size_t size, int *count, int *output)
{
	ssize_t i;
	int value, pos;

	for (i = (ssize_t)size - 1; i >= 0; i--)
	{
		value = array[i];
		pos = count[value] - 1;
		output[pos] = value;
		count[value] -= 1;
	}
}

/**
 * copy_back - copies output array back into original array
 * @array: original array
 * @output: sorted output array
 * @size: number of elements
 */
static void copy_back(int *array, int *output, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort
 * @array: array of integers
 * @size: number of elements in array
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

	build_count_array(array, size, count, k);
	prefix_sum_and_print(count, k);
	build_output(array, size, count, output);
	copy_back(array, output, size);

	free(output);
	free(count);
}
