/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 07:16:16 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/27 07:27:59 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isblank(char c)
{
	return ((c == ' ' || c == '\t') ? 1 : 0);
}

void	expand_str(char *s)
{
	int	i = 0;
	int	wc = 0;

	while (s[i])
		if (!ft_isblank(s[i++]) && (!wc || ft_isblank(s[i - 2])))
			++wc;
	i = 0;
	while (s[i])
	{
		if (!ft_isblank(s[i++]) && wc--)
		{
			write (1, &s[i - 1], 1);
			while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));
			(wc) ? write(1, "   ", 3) : 0;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
}
