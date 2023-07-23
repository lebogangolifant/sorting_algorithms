#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index start
 *
 * @array: The array to sort
 * @start: The root index
 * @end: The end index
 * @size: Size of the array
 */

static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t swap, child;
	int tmp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;

		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to sort
 * @size: Size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t swap;
	int tmp;

	for (swap = size / 2 - 1; swap >= 1; swap--)
		sift_down(array, swap, size - 1, size);

	for (swap = size - 1; swap > 0; swap--)
	{
		tmp = array[0];
		array[0] = array[swap];
		array[swap] = tmp;

		print_array(array, size);

		sift_down(array, 0, swap - 1, size);
	}
}
