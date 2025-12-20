#include "sort.h"
#include <stdlib.h>

/**
 * get_max - returns the maximum value in an array
 * @array: array of ints
 * @size: number of elements
 *
 * Return: max value
 */
static int get_max(int *array, size_t size)
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
 * build_count - builds count array and prefix sums, then prints it
 * @array: array of ints
 * @size: number of elements
 * @count: count array
 * @k: maximum value
 */
static void build_count(int *array, size_t size, int *count, int k)
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
 * fill_output - fills output array using prefix sums, then copies back
 * @array: original array
 * @size: number of elements
 * @count: prefix sums array
 * @output: output array
 */
static void fill_output(int *array, size_t size, int *count, int *output)
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
 * counting_sort - sorts an array of ints in ascending order (Counting sort)
 * @array: array of ints
 * @size: number of elements
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int k;

	if (array == NULL || size < 2)
		return;

	k = get_max(array, size);

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	build_count(array, size, count, k);
	fill_output(array, size, count, output);

	free(output);
	free(count);
}
