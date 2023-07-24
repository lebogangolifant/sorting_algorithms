#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @left: A pointer to the first node to swap.
 * @right: The second node to swap.
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (right->next)
		right->next->prev = left;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order
 *
 * @list: Pointer to a pointer to the first element of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		listint_t *insertion_point = current->prev;

		while (insertion_point && current->n < insertion_point->n)
		{
			swap_nodes(list, insertion_point, current);
			insertion_point = current->prev;
			print_list((const listint_t *)*list);
		}

		current = current->next;
	}
}
