/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/20 19:52:57 by jocluzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"


int push(t_exam *exam)
{
	int n;
	float sec;

	n = rand() % 30 + 10;
	FILE *file;
	#define INTERVAL (0.4 * CLOCKS_PER_SEC)

	int i = 0;
	int v = 0;
    clock_t target;
    char spin[] = "\\|/-";
    printf(" ");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    while(v < n) {
        printf("\b%c", spin[i]);
        fflush(stdout);
		v++;
        i = (i + 1) % 4;
        target = clock() + (clock_t)INTERVAL;
        while (clock() < target);
    }
	system("sh .system/verif/tester.sh");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    if ((file = ((fopen(".system/verif/passed", "r")))))
    {
		printf("\n\x1B[32m\n #####  #     #  #####   #####  #######  #####   #####\n#     # #     # #     # #     # #       #     # #     #\n#       #     # #       #       #       #       #\n #####  #     # #       #       #####    #####   #####\n      # #     # #       #       #             #       #\n#     # #     # #     # #     # #       #     # #     #\n #####   #####   #####   #####  #######  #####   #####  \x1B[37m\n\n");
		exam->midlev++;
		if (exam->midlev == 2)
		{
			exam->midlev = 0;
			exam->folder_num++;
		}
		exam->level += 12.5;
		system("sh .system/passed.sh");
		s_sleep(3);
		if (exam->level == 100)
			success_exam(exam);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\x1B[32mCongratulation!\x1B[37m A new subject is now created.\n\n       Note actuelle : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
		printf("\x1B[32mhelp\x1B[37m pour obtenir de l'aide");
		printf("\n\x1B[32mpush\x1B[37m pour rendre l'exercice");
    	printf("\n\x1B[32mexit\x1B[37m pour abandonner");
    	printf("\n\x1B[32mtime\x1B[37m pour connaitre le temps restant\n\n");
    	display_end(exam->depart);
		generate_subject(exam);
		exam->failuretime = 0;
	}
	else
	{
		printf("\n\x1B[31m#######    #    ### #           #    ##\n#         # #    #  #          ###  #\n#        #   #   #  #           #  #\n#####   #     #  #  #              #\n#       #######  #  #           #  #\n#       #     #  #  #          ###  #\n#       #     # ### #######     #    ##\x1B[37m\n\n");
		s_sleep(3);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\x1B[37mRetrouver la trace dans le fichier \x1B[31m> traceback\x1B[37m\n\n       Note actuelle : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
		printf("\x1B[32mhelp\x1B[37m pour obtenir de l'aide");
		printf("\n\x1B[32mpush\x1B[37m pour rendre l'exercice");
    	printf("\n\x1B[32mexit\x1B[37m pour abandonner");
    	printf("\n\x1B[32mtime\x1B[37m pour connaitre le temps restant\n\n");
    	display_end(exam->depart);
		if (exam->failuretime == 0)
			exam->failuretime = 15;
		exam->failuretime = exam->failuretime * 1.9; // A REMPLACER PAR 1.9 !
		time(&exam->timestart);
		time(&exam->timeend);
		exam->timeend += exam->failuretime;
	}
	return (0);
}

int		success_exam(t_exam *exam)
{
	float seconds;
    int sec;
    int hours;
    int minutes;
	time_t arrivee;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\x1B[32mCongratulation!\x1B[37m Tu as terminé l'examen %d à 100%% ! \n\n",exam->exam_type);
	time(&arrivee);
    seconds = difftime(exam->depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mAvec : \x1B[32m%d H %d M %d S\n\n\x1B[37m de temps restants.", hours, minutes, sec);
    system("make reset");
    exit(0);
}
