#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_parts - Merge two sorted subarrays into one sorted segment
 * @array: Original array
 * @buff: Temporary buffer (allocated once)
 * @left: Left index (inclusive)
 * @mid: Middle index (exclusive)
 * @right: Right index (exclusive)
 */
static void merge_parts(int *array, int *buff, size_t left, size_t mid,
			size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buff[k++] = array[i++];
		else
			buff[k++] = array[j++];
	}

	while (i < mid)
		buff[k++] = array[i++];

	while (j < right)
		buff[k++] = array[j++];

	for (k = left; k < right; k++)
		array[k] = buff[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split_merge - Recursively split and merge (top-down merge sort)
 * @array: Original array
 * @buff: Temporary buffer (allocated once)
 * @left: Left index (inclusive)
 * @right: Right index (exclusive)
 */
static void split_merge(int *array, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	/* Left size <= Right size because of integer division */
	split_merge(array, buff, left, mid);
	split_merge(array, buff, mid, right);
	merge_parts(array, buff, left, mid, right);
}

/**
 * merge_sort - Sort an array using the merge sort algorithm (top-down)
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	split_merge(array, buff, 0, size);

	free(buff);
}
