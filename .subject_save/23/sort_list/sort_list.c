// Passed Moulinette 2019.09.01

#include "list.h"

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}

//----------------------------------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

// int	main(void)
// {
// 	t_list *c = malloc(sizeof(t_list));
// 	c->next = 0;
// 	c->data = 45;

// 	t_list *b = malloc(sizeof(t_list));
// 	b->next = c;
// 	b->data = 73;

// 	t_list *a = malloc(sizeof(t_list));
// 	a->next = b;
// 	a->data = 108;

// 	t_list *cur = a;
// 	while (cur)
// 	{
// 		printf("%d, ", cur->data);
// 		cur = cur->next;
// 	}
// 	printf("\n");

// 	cur = sort_list(a, ascending);

// 	// cur = a;
// 	while (cur)
// 	{
// 		printf("%d, ", cur->data);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }