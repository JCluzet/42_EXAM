/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:05:27 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/21 12:42:46 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

void	epurstr(char *s)
{
	int len = ft_strlen(s);

	while (len && ft_isblank(s[len - 1]))
		--len;
	while (len && ft_isblank(*s) && *s++)
		--len;
	while (len--)
	{
		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))
			write(1, s, 1);
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		epurstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
