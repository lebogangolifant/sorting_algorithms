#include "sort.h"

/**
 * get_max - Get the maximum value in the array
 *
 * @array: The array to sort
 * @size: Size of the array
 * Return: The maximum value
 */

static int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t index;

	for (index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * counting_sort_radix - Counting sort for Radix sort
 *
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The exponent, i.e., 1, 10, 100, etc.
 */

static void counting_sort_radix(int *array, ssize_t size, int exp)
{
	int *output = NULL;
	ssize_t index;
	int count[10] = {0};

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (index = 0; index < size; index++)
		count[(array[index] / exp) % 10]++;

	for (index = 1; index < 10; index++)
		count[index] += count[index - 1];

	/* Build the output array */
	for (index = size - 1; index >= 0; index--)
	{
		output[count[(array[index] / exp) % 10] - 1] = array[index];
		count[(array[index] / exp) % 10]--;
	}

	/* Copy the output array to array[]*/
	for (index = 0; index < size; index++)
		array[index] = output[index];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to sort
 * @size: Size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max;
	ssize_t exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
