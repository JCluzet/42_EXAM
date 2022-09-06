/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:49:32 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/03 17:49:38 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_alpha_mirror(int c)
{
	return (c = (c >= 'A' && c <= 'Z') ? 'Z' - (c - 'A') : 'z' - (c - 'a'));
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1])
		{
			if (ft_isalpha(*av[1]))
				ft_putchar(ft_alpha_mirror(*(av[1]++)));
			else
				write(1, av[1]++, 1);
		}
	}
	write(1, "\n", 1);
	return (1);
}
