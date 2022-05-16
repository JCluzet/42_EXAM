/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:09:13 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 17:25:25 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int neg;


	i = 0;
	nbr = 0;
	neg = 1;
	if(str[0] == '-' || str[0] == '+')
			i++;
	if(str[0] == '-')
		neg = -1;
	while (str[i] != '\0' && str[i]>= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (neg * nbr);
}

/*int	main(void)
{
	int	result;

	result = ft_atoi("-42abc");
	printf("%d\n", result);
} 	*/