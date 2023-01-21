#include "sort.h"

/**
 * swap - swaps nodes positions
 * @node1: the first node
 * @node2: the second node
 * Return: the second node
 */

listint_t *swap(listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = node1;
	if (node1->prev)
		node1->prev->next = node2;
	node2->prev = node1->prev;
	node1->prev = node2;

	return (node2);
}

/**
 * insertion_sort_list - sorts doubly linked list
 * @list: pointer to pointer to the head of the list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1 = NULL;
	listint_t *tmp2 = NULL;

	if (!(list) || !(*list) || !((*list)->next))
		return;

	tmp1 = (*list)->next;
	while (tmp1)
	{
		tmp2 = tmp1;
		while (tmp2->prev)
		{
			if (tmp2->n < tmp2->prev->n)
			{
				tmp2 = swap(tmp2->prev, tmp2);
				if (tmp2->prev == NULL)
					*list = tmp2;
				print_list(*list);
				continue;
			}
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->next;
	}
}
