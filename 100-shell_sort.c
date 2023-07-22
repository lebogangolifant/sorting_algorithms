#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (size_t outer = interval; outer < size; outer++)
		{
			int current = array[outer];
			size_t inner = outer;

			while (inner >= interval && array[inner - interval]
					> current)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}

			array[inner] = current;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
