#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t outer, inner, min_index;

	if (array == NULL || size < 2)
		return;

	for (outer = 0; outer < size - 1; outer++)
	{
		min_index = outer;

		for (inner = outer + 1; inner < size; inner++)
		{
			if (array[inner] < array[min_index])
				min_index = inner;
		}

		if (min_index != outer)
		{
			int temp = array[outer];

			array[outer] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
