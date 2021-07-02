/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/02 15:24:25 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"


int push(t_exam *exam)
{
	int n;
	float sec;

	n = rand() % 40 + 10;
	FILE *file;
	#define INTERVAL (0.4 * CLOCKS_PER_SEC)

	int i = 0;
	int v = 0;
    clock_t target;
    char spin[] = "\\|/-";
	blank();
    while(v < n) {
        printf("\b%c", spin[i]);
        fflush(stdout);
		v++;
        i = (i + 1) % 4;
        target = clock() + (clock_t)INTERVAL;
        while (clock() < target);
    }
	system("sh .system/verif/tester.sh");
	blank();

    if ((file = ((fopen(".system/verif/passed", "r")))))
    {
		printf("\n\x1B[32m\n #####  #     #  #####   #####  #######  #####   #####\n#     # #     # #     # #     # #       #     # #     #\n#       #     # #       #       #       #       #\n #####  #     # #       #       #####    #####   #####\n      # #     # #       #       #             #       #\n#     # #     # #     # #     # #       #     # #     #\n #####   #####   #####   #####  #######  #####   #####  \x1B[37m\n\n");
		exam->midlev++;
		if (exam->midlev == 2)
		{
			exam->midlev = 0;
			exam->folder_num++;
		}
		exam->level += XP_BY_LEVEL;
		system("sh .system/passed.sh");
		s_sleep(3);
		if (exam->level == XP_TO_FINISH)
			success_exam(exam);
		blank();
		printf("\x1B[32mCongratulation!\x1B[37m A new subject is now created.\n\n       Current Grade : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
    	printf("\x1B[32mhelp\x1B[37m to get some help");
    	printf("\n\x1B[32mpush\x1B[37m to get corrected");
    	printf("\n\x1B[32mexit\x1B[37m to left");
    	printf("\n\x1B[32mtime\x1B[37m to know the remaining time\n\n");
    	display_end(exam->depart);
		generate_subject(exam);
		exam->failuretime = 0;
	}
	else
	{
		printf("\n\x1B[31m#######    #    ### #           #    ##\n#         # #    #  #          ###  #\n#        #   #   #  #           #  #\n#####   #     #  #  #              #\n#       #######  #  #           #  #\n#       #     #  #  #          ###  #\n#       #     # ### #######     #    ##\x1B[37m\n\n");
		s_sleep(3);
		blank();
		printf("\x1B[37mFind the trace in the file \x1B[31m> traceback\x1B[37m\n\n       Current Grade : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
   		printf("\x1B[32mhelp\x1B[37m to get some help");
    	printf("\n\x1B[32mpush\x1B[37m to get corrected");
    	printf("\n\x1B[32mexit\x1B[37m to left");
    	printf("\n\x1B[32mtime\x1B[37m to know the remaining time\n\n");
    	display_end(exam->depart);
		exam->nbfail++;
		if (exam->failuretime == 0)
			exam->failuretime = 15;
		exam->failuretime = exam->failuretime * FAILURE_TIME;
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
	blank();
	printf("\x1B[32mCongratulation!\x1B[37m You have completed the exam \x1B[31m%d with %d fail\x1B[37m \n\n",exam->exam_type, exam->nbfail);
	time(&arrivee);
    seconds = difftime(exam->depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mWith: \x1B[32m%d H %d M %d S  \x1B[37m time left.", hours, minutes, sec);
    system("make reset");
    exit(0);
}
