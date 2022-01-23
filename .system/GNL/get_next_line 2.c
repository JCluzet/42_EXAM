/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:13:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/06 00:54:07 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(char *buff)
{
	int index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}

int		readfile(int fd, char *buff, char *str)
{
	int ret;

	if (str)
	{
		ft_strcpy(buff, str);
		free(str);
		return (1);
	}
	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	return (ret);
}

char	get_this_line(int fd, char **line, t_gnl gnl)
{
	static char *str;

	*line = ft_strdup("");
	while ((gnl.ret = (readfile(fd, gnl.buff, str))) > 0)
	{
		if (str)
			str = NULL;
		if (!(ft_strchr(gnl.buff)))
		{
			gnl.index = 0;
			while (gnl.buff[gnl.index] != '\n')
				gnl.index++;
			gnl.buff[gnl.index] = '\0';
			if (!str)
				str = ft_strdup(gnl.buff + gnl.index + 1);
			*line = ft_strjoin(line, gnl.buff);
			return (1);
		}
		else
			*line = ft_strjoin(line, gnl.buff);
	}
	if (*line == NULL)
		*line = ft_strdup("");
	return (gnl.ret);
}

int		get_next_line(int fd, char **line)
{
	t_gnl			gnl;

	gnl.index = 0;
	if (!line || BUFFER_SIZE < 1 || read(fd, gnl.buff, 0) < 0)
		return (-1);
	return (get_this_line(fd, line, gnl));
}
