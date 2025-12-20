#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sort an array using Counting sort
 * @array: Array to sort (contains only numbers >= 0)
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i;
	int max, v;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i < (size_t)(max + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < (size_t)(max + 1); i++)
		count[i] += count[i - 1];

	/* print counting array once it is set up */
	print_array(count, (size_t)(max + 1));

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	/* stable placement: iterate from end */
	for (i = size; i > 0; i--)
	{
		v = array[i - 1];
		output[count[v] - 1] = v;
		count[v]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
