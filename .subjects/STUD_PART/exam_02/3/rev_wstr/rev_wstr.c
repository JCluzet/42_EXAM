/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:16:31 by jcharloi          #+#    #+#             */
/*   Updated: 2022/12/14 17:54:50 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int		ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	fonction(char *str)
{
	char *copy;
	int	size;
	int	i;
	int	o;
	int mot;
	
	size = 1;
	o = 0;
	mot = 0;
	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return ;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		while (str[i] != ' ' && i >= 0)
		{
			size++;
			i--;
		}
		size++;
		i++;
		while (str[i] != '\0' && str[i] != ' ')
		{
			copy[o] = str[i];
			o++;
			i++;
		}
		if (size <= ft_strlen(str) + 1)
			copy[o++] = ' ';
		mot++;
		i = ft_strlen(str) - size;
	}
	//copy[i] = '\0';
	ft_putstr(copy);
	//noublie pas le \0
}

int main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		str = argv[1];
		fonction(str);		
	}
	ft_putstr("\n");
	return (0);
}