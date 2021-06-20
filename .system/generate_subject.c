/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_subject.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/20 17:47:32 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"

int	generate_subject(t_exam *exam)
{
	system("mkdir rendu");
	if (exam->folder_num == 1)
		system("sh .system/generatesub.sh 1");
	if (exam->folder_num == 2)
		system("sh .system/generatesub.sh 2");
	if (exam->folder_num == 3)
		system("sh .system/generatesub.sh 3");
	if (exam->folder_num == 4)
		system("sh .system/generatesub.sh 4");
	if (exam->folder_num == 5)
		system("sh .system/generatesub.sh 5");
	if (exam->folder_num == 6)
		system("sh .system/generatesub.sh 6");
	if (exam->folder_num == 7)
		system("sh .system/generatesub.sh 7");
	if (exam->folder_num == 8)
		system("sh .system/generatesub.sh 8");
	if (exam->folder_num == 9)
		system("sh .system/generatesub.sh 9");
	if (exam->folder_num == 10)
		system("sh .system/generatesub.sh 10");
	return (0);
}
