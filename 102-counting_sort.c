#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	int value;
	size_t index;
	int sorted_index = 0;
	size_t max_value = array[0];
	int *counting_array = malloc((max_value + 1) * sizeof(int));

	if (size <= 1)
		return;

	for (index = 1; index < size; index++)
	{
		if ((size_t)array[index] > max_value)
			max_value = array[index];
	}

	if (!counting_array)
		return;

	for (index = 0; index <= max_value; index++)
		counting_array[index] = 0;

	for (index = 0; index < size; index++)
		counting_array[array[index]]++;

	print_array(counting_array, max_value + 1);

	for (value = 0; value <= (int)max_value; value++)
	{
		while (counting_array[value] > 0)
		{
			array[sorted_index++] = value;
			counting_array[value]--;
		}
	}

	free(counting_array);
}
