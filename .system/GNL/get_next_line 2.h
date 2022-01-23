/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:57:48 by jcluzet           #+#    #+#             */
/*   Updated: 2020/02/18 22:57:50 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct	s_gnl
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			index;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char **line, char *buff);
int				readfile(int fd, char *buff, char *str);
char			get_this_line(int fd, char **line, t_gnl gnl);
char			*ft_strdup(const char *s);
int				ft_strchr(char *buff);
int				ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);

#endif
