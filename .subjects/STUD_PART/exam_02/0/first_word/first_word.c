/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:19:21 by galpers           #+#    #+#             */
/*   Updated: 2022/04/04 14:24:21 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t') // si space ou tab passer au char suivant
			i++;
		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t') // si fin de chaine de char ET espace ET tab
		{
			write(1, &av[1][i], 1); // alors print le texte 
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
