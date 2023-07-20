#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order
 *
 * @list: Pointer to a pointer to the first element of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *next_node;
	listint_t *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current; current = next_node)
	{
		next_node = current->next;
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node && prev_node->n > current->n)
		{
			if (next_node)
				next_node->prev = prev_node;

			current->prev = prev_node->prev;
			if (prev_node->prev)
				prev_node->prev->next = current;
			else
				*list = current;

			prev_node->next = next_node;
			prev_node->prev = current;
			current->next = prev_node;

			prev_node = current->prev;
			print_list(*list);
		}
	}
}
