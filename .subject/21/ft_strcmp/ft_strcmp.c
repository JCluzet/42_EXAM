/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:27:47 by galpers           #+#    #+#             */
/*   Updated: 2022/05/30 15:06:02 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*int	main(void)
{
	printf("Original vs Clone: <%d> <%d>", strcmp("hello World", "hello world") , ft_strcmp("hello World", "hello world"));
	printf("\nOriginal vs Clone: <%d> <%d>", strcmp("hello World", "") , ft_strcmp("hello World", ""));

}*/
