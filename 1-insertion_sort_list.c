#include "sort.h"
/**
 * switch - fonction switch 2 nodes
 * @s: the big node
 * @b: the small node
 */
void twitch(listint_t *s, listint_t *b)
{
	if (s->prev)
		s->prev->next = b;
	if (b->next)
		b->next->prev = s;
	s->next = b->next;
	b->prev = s->prev;
	s->prev = b;
	b->next = s;
}
/**
 * insertion_sort_list - function that sorts a list of integers
 * @list: list of integers
 * Return: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *big, *small;

	if (!(*list)->next)
		return;
	big = (*list)->next;
	while (big)
	{
		small = big;
		while (small->prev)
		{
			if (small->prev->n > small->n)
			{
				twitch(small->prev, small);
				if (!small->prev)
					*list = small;
				print_list(*list);
			}
			else
				small = small->prev;
		}
		big = big->next;
	}
}
