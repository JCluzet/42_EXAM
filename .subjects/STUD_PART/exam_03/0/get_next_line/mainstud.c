/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by jcluzet           #+#    #+#             */
/*   Updated: 2023/01/13 02:24:31 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	system("leaks stud > studleak 2>&1");
	return(0);
}
