/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:20:46 by salquier          #+#    #+#             */
/*   Updated: 2019/03/25 15:16:27 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO REFERENCE, BUT DO NOT PUSH THIS FILE
#include "list.h"

int        cycle_detector(const t_list *list)
{
	const t_list	*slow;
	const t_list	*fast;

	slow = list;
	fast = list;
	if (!list)
		return (0);
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	t_list *node4;

// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	node3 = malloc(sizeof(t_list));
// 	node4 = malloc(sizeof(t_list));

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;
// 	node4->next = node2;

// 	printf("%d\n", cycle_detector(node1));
// }
