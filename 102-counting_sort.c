#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t index;
	int max_value = array[0];
	int *counting_array, *sorted_array;

	if (!array || size < 2)
		return;

	for (index = 1; index < size; index++)
	{
		if (array[index] > max_value)
			max_value = array[index];
	}
	counting_array = malloc((max_value + 1) * sizeof(int));
	if (!counting_array)
		return;

	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}

	for (index = 0; index <= (size_t)max_value; index++)
		counting_array[index] = 0;
	for (index = 0; index < size; index++)
		counting_array[array[index]]++;
	for (index = 1; index <= (size_t)max_value; index++)
		counting_array[index] += counting_array[index - 1];
	print_array(counting_array, max_value + 1);

	for (index = 0; index < size; index++)
	{
		sorted_array[counting_array[array[index]] - 1] = array[index];
		counting_array[array[index]]--;
	}
	for (index = 0; index < size; index++)
		array[index] = sorted_array[index];
	free(counting_array);
	free(sorted_array);
}
