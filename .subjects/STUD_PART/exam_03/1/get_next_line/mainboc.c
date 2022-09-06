/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainboc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by jcluzet           #+#    #+#             */
/*   Updated: 2022/09/03 17:52:19 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

int
	main(void)
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
	system("leaks boc > bocleak 2>&1");
	return(0);
}
