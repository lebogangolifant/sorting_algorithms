#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */

static void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Merges two subarrays of a Bitonic sequence
 *
 * @array: The array to sort
 * @low: Lower index of the subarray
 * @count: Number of elements to merge
 * @dir: Sort direction (1 for ascending, 0 for descending)
 */

static void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t step = count / 2;
	size_t index;

	if (count > 1)
	{
		for (index = low; index < low + step; index++)
		{
			if ((array[index] > array[index + step]) == dir)
				swap(&array[index], &array[index + step]);
		}

		if (step > 1)
		{
			bitonic_merge(array, low, step, dir);
			bitonic_merge(array, low + step, step, dir);
		}
	}
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort
 *
 * @array: The array to sort
 * @low: Lower index of the subarray
 * @count: Number of elements to sort
 * @dir: Sort direction (1 for ascending, 0 for descending)
 */

static void bitonic_sort_recursive(int *array, size_t low, size_t count,
		int dir)
{
	size_t step;

	if (count > 1)
	{
		step = count / 2;
		bitonic_sort_recursive(array, low, step, 1);
		bitonic_sort_recursive(array, low + step, step, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *
 * @array: The array to sort
 * @size: Size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	int *temp_array = malloc(sizeof(int) * size);

	if (array == NULL || size < 2)
		return;

	if (temp_array == NULL)
		return;

	memcpy(temp_array, array, sizeof(int) * size);

	bitonic_sort_recursive(temp_array, 0, size, 1);

	free(temp_array);
}
