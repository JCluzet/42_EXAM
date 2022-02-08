/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2022/02/08 01:20:14 by jcluzet          ###   ########.fr       */
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
	system("bash .system/verif/tester.sh");
	blank();

    if ((file = ((fopen(".system/verif/passed", "r")))))
    {
		printf("\n\x1B[32m >>>>>>>> SUCCESS <<<<<<<<< \x1B[37m\n\n");
		exam->midlev++;
		if (exam->midlev == exam->exbylvl)
		{
			exam->midlev = 0;
			exam->folder_num++;
		}
		exam->level += exam->xpperex;
		system("bash .system/passed.sh");
		s_sleep(3);
		if (exam->level == 100)
			success_exam(exam);
		blank();
		printf("\x1B[32mCongratulation!\x1B[37m Your work as been saved in \x1B[32msuccess/\x1B[37m folder.\n A new subject is now created.\n\n");
		generate_subject(exam);
		printf("    CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[37m\n\n", exam->level);
    printf("   CURRENT PROJECT\n   ---> \x1B[32m%s      \x1B[37mfor :\x1B[32m %.2f\x1B[37m XP 🧪 \n\n", exam->nameofex, exam->xpperex);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mexit\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time\n\n");
    	display_end(exam->depart);
		exam->failuretime = 0;
	}
	else
	{
		printf("\n\x1B[32m <<<<<<<<<< FAILURE >>>>>>>>>> \x1B[37m\n\n");
		s_sleep(3);
		blank();
		if (exam->trace)
			printf("Normally the traceback is not available for this exam at 42\nbut since it is a training, it is available here :)");
		printf("\n\n\x1B[37mFind the trace in the file \x1B[31m> traceback\x1B[37m\n\n");
		printf("    CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[37m\n\n", exam->level);
    printf("   CURRENT PROJECT\n   ---> \x1B[32m%s      \x1B[37mfor :\x1B[32m %.2f\x1B[37m XP 🧪 \n\n", exam->nameofex, exam->xpperex);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mexit\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time\n\n");
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
	printf("\x1B[32mCongratulation!\x1B[37m You have completed the exam %d with \x1B[31m%d fail\x1B[37m \nYour work as been saved in success folder.\n\n",exam->exam_type, exam->nbfail);
	time(&arrivee);
    seconds = difftime(exam->depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mWith: \x1B[32m%d H %d M %d S  \x1B[37m time left.\n", hours, minutes, sec);
    system("make reset");
    exit(0);
}
