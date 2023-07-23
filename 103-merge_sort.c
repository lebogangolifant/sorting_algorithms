#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 * @array: Pointer to the original array
 * @size: Size of the original array
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 */

static void merge(int *array, size_t size, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t idx = 0, left_idx = 0, right_idx = 0;
	int *temp_array = malloc(size * sizeof(int));

	if (!temp_array)
		return;

	while (left_idx < left_size && right_idx < right_size)
	{
		if (left[left_idx] <= right[right_idx])
			temp_array[idx++] = left[left_idx++];
		else
			temp_array[idx++] = right[right_idx++];
	}

	while (left_idx < left_size)
		temp_array[idx++] = left[left_idx++];

	while (right_idx < right_size)
		temp_array[idx++] = right[right_idx++];

	for (idx = 0; idx < size; idx++)
		array[idx] = temp_array[idx];

	free(temp_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t middle = size / 2;
		size_t left_size = middle;
		size_t right_size = size - middle;
		int *left = array;
		int *right = array + middle;

		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, size, left, left_size, right, right_size);
	}
}
