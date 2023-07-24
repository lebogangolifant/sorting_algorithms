#include "sort.h"

void quick_sort_recursive(int *array, int low, int high);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The pivot index after rearranging the elements
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int partition_index = low - 1, current_index, temp;

	for (current_index = low; current_index < high; current_index++)
	{
		if (array[current_index] < pivot)
		{
			partition_index++;
			if (partition_index != current_index)
			{
				temp = array[partition_index];
				array[partition_index] = array[current_index];
				array[current_index] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if (array[partition_index + 1] != array[high])
	{
		temp = array[partition_index + 1];
		array[partition_index + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}

	return (partition_index + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */

void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high);

		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}
