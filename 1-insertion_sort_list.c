#include "sort.h"
/**
 * node_find - this func finds the ith node on 
 * the list
 * @node: headnode
 * @i: position of the node
 * Return: node at index position
 */
listint_t *node_find(listint_t *node, int i)
{
	int j = 0;

	while (j < i)
	{
		j++;
		node = node->next;
	}
	return (node);

}
/**
 * node_count - this func count the nodes in list
 * @node: headnode
 * Return: number of nodes
 */
int node_count(listint_t *node)
{
	int count = 0;

	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
/**
 * insertion_sort_list -  this func sorts a
 * doubly linked list of integers in 
 * ascending order using the insertion sort algo
 * print the list after each time you swap two elements
 * @list: listint_t node pointer
 */

void insertion_sort_list(listint_t **list)
{
	int i, n, temp;
	listint_t *node = NULL, *tmp = NULL, *node_next = NULL, *node_prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	n = node_count(*list);
	for (i = 1; i < n; i++)
	{
		node = *list;
		node = node_find(node, i);
		tmp = node;
		temp = node->n;
		while ((node->prev != NULL) && (node->prev->n > temp))
		{
			node_prev = node->prev;
			if (node->next)
			{
				node_next = node->next;
				node_prev->next = node_next;
				node_next->prev = node_prev;
			}
			else
				node_prev->next = NULL;
			node = node_prev;
			tmp->next = node;
			if (node->prev == NULL)
			{
				tmp->prev = NULL;
				*list = tmp;
			}
			else
			{
				tmp->prev = node->prev;
				tmp->prev->next = tmp;
			}
			node->prev = tmp;
			node = tmp;
			print_list(*list);
		}
	}
}
