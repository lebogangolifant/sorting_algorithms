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
 * partition - Partitions an array using the Hoare scheme
 *
 * @array: The array to be partitioned
 * @low: Lower bound of the partition
 * @high: Upper bound of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partition
 */

static size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t left = low - 1, right = high + 1;

	while (1)
	{
		do {
			left++;
		} while (left < (ssize_t)size && array[left] < pivot);

		do {
			right--;
		} while (right >= 0 && array[right] > pivot);

		if (left >= right)
			return (right);

		swap(&array[left], &array[right]);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 *
 * @array: The array to sort
 * @low: Lower bound of the partition
 * @high: Upper bound of the partition
 * @size: Size of the array
 */

static void quick_sort_recursive(int *array, ssize_t low, ssize_t high,
		size_t size)
{
	if (low < high)
	{
		ssize_t partition_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *
 * @array: The array to sort
 * @size: Size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
