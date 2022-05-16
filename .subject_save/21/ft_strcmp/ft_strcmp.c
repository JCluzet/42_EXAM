/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:27:47 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 18:14:57 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
	 		i++;
		else if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	if (s1[i] > s2[i])
			return (1);
	else if (s1[i] < s2[i])
			return (-1);
	else 
			return (0);
	}

/*int	main(void)
{
	printf("Original vs Clone: <%d> <%d>", strcmp("hello World", "hello world") , ft_strcmp("hello World", "hello world"));
	printf("\nOriginal vs Clone: <%d> <%d>", strcmp("hello World", "") , ft_strcmp("hello World", ""));

}*/
