/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:58:23 by jcluzet           #+#    #+#             */
/*   Updated: 2020/02/21 19:38:46 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*moulitruc;
	int		i;
	int		u;

	i = 0;
	u = (int)ft_strlen(s);
	moulitruc = malloc(sizeof(char) * u + 1);
	if (moulitruc == NULL)
		return (NULL);
	while (s[i])
	{
		moulitruc[i] = s[i];
		i++;
	}
	moulitruc[i] = '\0';
	return (moulitruc);
}

char	*ft_strjoin(char **line, char *buff)
{
	char	*tmp;
	int		i;
	int		u;

	i = ft_strlen(buff);
	if (!(tmp = malloc(i + ft_strlen(*line) + 1)))
		return (NULL);
	i = 0;
	u = 0;
	while ((*line)[u])
	{
		tmp[i] = (*line)[u];
		i++;
		u++;
	}
	u = 0;
	while (buff[u])
	{
		tmp[i] = buff[u];
		i++;
		u++;
	}
	free((char*)*line);
	tmp[i] = '\0';
	return (tmp);
}
