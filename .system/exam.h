/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 22:21:03 by jocluzet          #+#    #+#             */
/*   Updated: 2022/01/17 00:07:33 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAM_H
# define EXAM_H

# define FAILURE_TIME 1.9

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_exam
{
	int			lol;
	time_t		depart, arrivee;
	char *		heure;
	int 		start;
	int 		exbylvl;
	float		xpperex;
	int			trace;
	int			midlev;
	int			failuretime;
	char		nameofex[100];
	float 		level;
	int			nbfail;
	time_t		timestart, timeend;
	int			exam_type;
	int			folder_num;
}				t_exam;

int				start(t_exam *exam);
void   			blank(void) ;
int				push(t_exam *exam);
int				generate_subject(t_exam *exam);
int				success_exam(t_exam *exam);
int				help(t_exam *exam);
void			instruction(t_exam *exam);
int				ft_strcmp(char *s1, char *s2);
int				time_left(time_t depart, t_exam *exam);
int				get_next_line(int fd, char **line);
int				dispatcheur(t_exam *exam, char *buf);
void			s_sleep(int seconds);
void			display_end(time_t depart);
void			header(t_exam *exam);

#endif
