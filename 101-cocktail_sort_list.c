#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the list
 * @left: First node to swap
 * @right: Second node to swap
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *
 * @list: Pointer to a pointer to the first element of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = NULL;
	do {
		swapped = 0;
		left = *list;

		while (left->next != end)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				print_list(*list);
				swapped = 1;
			} else
			{
				left = left->next;
			}
		}
		end = left;
		left = left->prev;
		while (left != NULL && left->prev != end)
		{
			right = left->prev;
			if (left->n < right->n)
			{
				swap_nodes(list, right, left);
				print_list(*list);
				swapped = 1;
			} else
			{
				left = left->prev;
			}
		}
	} while (swapped);
}
