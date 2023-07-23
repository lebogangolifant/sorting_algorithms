#include "deck.h"

/**
 * compare_cards - Compare two card_t objects
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 is less than card2,
 *         0 if card1 is equal to card2,
 *         Positive value if card1 is greater than card2
 */

int compare_cards(const void *card1, const void *card2)
{
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"};
	card_t *c1 = (card_t *)card1;
	card_t *c2 = (card_t *)card2;
	int index, v1, v2;

	if (c1->kind != c2->kind)
		return (c1->kind - c2->kind);

	for (index = 0; index < 13; index++)
	{
		if (c1->value == values[index])
		{
			v1 = index;
			break;
		}
	}

	for (index = 0; index < 13; index++)
	{
		if (c2->value == values[index])
		{
			v2 = index;
			break;
		}
	}

	return (v1 - v2);
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */

void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *prev1, *next1;
	deck_node_t *prev2, *next2;

	prev1 = node1->prev;
	next1 = node1->next;
	prev2 = node2->prev;
	next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	node2->prev = prev1;
	node2->next = next1;
	if (next1)
		next1->prev = node2;

	if (prev2)
		prev2->next = node1;
	node1->prev = prev2;
	node1->next = next2;
	if (next2)
		next2->prev = node1;
}

/**
 * sort_deck - Sort a deck of cards in ascending order
 * @deck: Pointer to the pointer to the head of the deck
 */

void sort_deck(deck_node_t **deck)
{
	size_t i;
	size_t len;
	deck_node_t *current, *min_card;

	if (!deck || !*deck || !(*deck)->next)
		return;

	len = 0;
	current = *deck;

	while (current)
	{
		len++;
		current = current->next;
	}

	current = *deck;

	while (len > 1)
	{
		min_card = current;

		for (i = 0; i < len; i++)
		{
			if (compare_cards(current->card, min_card->card) < 0)
				min_card = current;
			current = current->next;
		}

		if (min_card != *deck)
			swap_nodes(min_card, *deck);
		*deck = min_card;
		len--;
		current = min_card->next;
	}
}
