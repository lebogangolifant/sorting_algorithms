#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order
 *
 * @list: Pointer to a pointer to the first element of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *sorted, *prev_sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		sorted = current->next;
		while (sorted && sorted->prev && sorted->n < sorted->prev->n)
		{
			prev_sorted = sorted->prev;
			if (prev_sorted->prev)
				prev_sorted->prev->next = sorted;
			else
				*list = sorted;
			if (sorted->next)
				sorted->next->prev = prev_sorted;

			prev_sorted->next = sorted->next;
			sorted->prev = prev_sorted->prev;
			sorted->next = prev_sorted;
			prev_sorted->prev = sorted;
			print_list(*list);
		}
		current = current->next;
	}
}
