#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @lhs: A pointer to the node before rhs.
 * @rhs: A pointer to the node after lhs.
 */
void swap_nodes(listint_t *lhs, listint_t *rhs)
{
	if (rhs->next)
		rhs->next->prev = lhs;
	if (lhs->prev)
		lhs->prev->next = rhs;
	lhs->next = rhs->next;
	rhs->next = lhs;
	rhs->prev = lhs->prev;
	lhs->prev = rhs;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion Sort algorithm.
 * @list: A double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *next;
	listint_t *prev;

	if (list != NULL && *list != NULL)
	{
		next = (*list)->next;
		while ((curr = next))
		{
			next = curr->next;
			prev = curr->prev;
			while (prev && prev->n > curr->n)
			{
				swap_nodes(prev, curr);
				prev = curr->prev;
				if (!prev)
					*list = curr;
				print_list(*list);
			}
		}
	}
}
