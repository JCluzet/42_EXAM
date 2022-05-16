/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:56:59 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 15:42:37 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	*a;
	int	*b;
	int	n1;
	int	n2;

	n1 = 9;
	n2 = 6;
	a = &n1;
	b = &n2;
	printf("Value of n1 is: %u and the value of n2 is: %u.", *a, *b);
	ft_swap(a, b);
	printf("\n");
	printf("Now the value of n1 is: %u and the value of n2 is: %u.", *a, *b);
}*/