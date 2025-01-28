/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:00:42 by marcsilv          #+#    #+#             */
/*   Updated: 2025/01/28 14:09:40 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strrev(char *str);

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *a = strdup(av[1]);
		printf("%s reversed is: %s\n", a , ft_strrev(av[1]));
	}
	return (0);
}

