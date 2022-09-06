/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:08:36 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/24 04:08:01 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

// gcc checkmate.c && ./a.out '..R.' '.Q..' '..BK' '...P' | cat -e
// B = 3      Rook = 2 and Queen == 6   an P == 1

int		checkmate(int ac, char **av)
{
	int		y = 0;
	int		x = 0;
	int		len = 0;
	int		b = 0;
	int		a = 0;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return (0);
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			if (m[y][x] == 'K')
			{
				a = x;
				b = y;
			}
			++x;
		}
		m[y][x] = 0;
		++y;
	}

	// checking if the King is endangered by a pawn
	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P')
		return (0);

	int		i = 0;
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R')
			return (0);
		if (i < b)
		{
			if (i < a && (m[b - i - 1][a - i - 1] == 'B' || m[b - i - 1][a - i - 1] == 'Q') )
				return (0);
			if (a + i < len && (m[b - i - 1][a + i + 1] == 'B' || m[b - i - 1][a + i + 1] == 'Q'))
				return (0);
		}
		if (b + i < len)
		{
			if (i < a && (m[b + i + 1] [a - i - 1] == 'B' || m[b + i + 1] [a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b + i + 1] [a + i + 1] == 'B' || m[b + i + 1] [a + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}


void	print(int ac, char **av)
{	
	int		len;
	int		x;
	int		y;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return ;
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return ;
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			++x;
		}
		m[y][x] = 0;
		++y;
	}
	// printing map
	y = 0;
	while (y < len)
	{
		write(1, m[y++], len);
		write(1, "\n", 1);
	}
}


int		main(int ac, char **av)
{
	if (ac > 1 && checkmate(ac, av))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	print(ac, av);
	return (0);
}
