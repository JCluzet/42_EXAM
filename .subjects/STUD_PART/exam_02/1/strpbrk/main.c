/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:55:35 by marcsilv          #+#    #+#             */
/*   Updated: 2025/01/28 13:04:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2);

int main(int ac, char **av)
{
	if (ac == 3)
		printf("ft_strcspn(\"%s\", \"%s\") = %s\n", av[1], av[2], ft_strpbrk(av[1], av[2]));
	return (0);
}
