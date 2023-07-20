#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass, current_index;
	int temp, swapped;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		swapped = 0;
		for (current_index = 0; current_index < size - pass - 1;
				current_index++)
		{
			if (array[current_index] > array[current_index + 1])
			{
				temp = array[current_index];
				array[current_index] = array[current_index + 1];
				array[current_index + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
