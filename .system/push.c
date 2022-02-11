/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2022/02/11 21:45:21 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"
#include <string.h>

char *tstrsub(char *s, unsigned int start, size_t len)
{
    char *s2;
    size_t i;

    i = 0;
    s2 = malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        s2[i] = s[start + i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char *fttt_strjoin(char *str, char *str1)
{
    char *s;
    int i;
    int j;

    i = 0;
    j = 0;
    s = malloc(sizeof(char) * (strlen(str) + strlen(str1) + 1));
    while (str[i] != '\0')
    {
        s[i] = str[i];
        i++;
    }
    while (str1[j] != '\0')
    {
        s[i + j] = str1[j];
        j++;
    }
    s[i + j] = '\0';
    return (s);
}

int push(t_exam *exam)
{
	int n;
	float sec;


	int temp = 0;
	n = rand() % 50 + 15;
	FILE *file;
	#define INTERVAL (0.8 * CLOCKS_PER_SEC)

	
	float i = 0;
	int v = 0;
    clock_t target;
    char spin[] = "\\|/-";
	blank();
	printf ("(10 sec is fast, 20 sec is expected, 2 min is anormal)\n\nwaiting...\n");
    while(v < n) {
		temp = rand() % 10 + 2;
        if (temp > 8 && i > 1)
		{
			temp = rand() % 3 + 1;
			if (temp == 3)
				printf ("waiting...\n");
		}
        fflush(stdout);
		v++;
        i++;
        target = clock() + (clock_t)INTERVAL;
        while (clock() < target);
    }
	system("bash .system/verif/tester.sh");
	blank();

    if ((file = ((fopen(".system/verif/passed", "r")))))
    {
		printf("\n\x1B[32m >>>>>>>> \x1B[1m\x1B[5mSUCCESS\033[0;m \x1B[32m<<<<<<<<< \x1B[37m\n\n");
		exam->midlev++;
		if (exam->midlev == exam->exbylvl)
		{
			exam->midlev = 0;
			exam->folder_num++;
		}
		exam->level += exam->xpperex;
		system("bash .system/passed.sh");
		s_sleep(4);
		if (exam->level > 99.8)
			success_exam(exam);
		printf("\x1B[32mCongratulation!\x1B[37m Your work as been saved in \x1B[32msuccess/\x1B[37m folder.\n A new subject is now created.\n\n");
		generate_subject(exam);
    blank();
    char *str;
    // get the pwd start with ~/
    char *pwd = getcwd(NULL, 0);
    char *home = getenv("HOME");
    // if home is in pwd, replace it by ~
    if (strstr(pwd, home) != NULL)
    {
        str = tstrsub(pwd, strlen(home) + 1, strlen(pwd) - strlen(home) - 1);
        str = fttt_strjoin("~/", str);
    }
    free(pwd);
    printf("    CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[3m\n\n", exam->level);
    printf("   CURRENT PROJECT\n   ---> \x1B[33m%s      \x1B[37m\n   for :\x1B[32m %.2f\x1B[37m XP 🧪 \n\n", exam->nameofex, exam->xpperex);
    printf("\x1B[5mAssignement\x1B[0;m  : %s/rendu/", str);
    printf("\n\x1B[5m\x1B[37mSubject\x1B[0;m      : %s/subject.en.txt\n\n\n\x1B[37m", str);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mexit\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time\n\n");
    display_end(exam->depart);
    free(str);
		exam->failuretime = 0;
	}
	else
	{
		printf("\n\x1B[31m <<<<<<<<<< \x1B[1m\x1B[5mFAILURE\033[0;m \x1B[31m>>>>>>>>>> \x1B[37m\n\n");
		s_sleep(3);
		blank();
		if (exam->trace)
			printf("Normally the traceback is not available for this exam at 42\nbut since it is a training, it is available here :)");
		printf("\n\n\x1B[37mFind the trace in the file \x1B[31m> traceback\x1B[37m\n\n");
    char *str;
    // get the pwd start with ~/
    char *pwd = getcwd(NULL, 0);
    char *home = getenv("HOME");
    // if home is in pwd, replace it by ~
    if (strstr(pwd, home) != NULL)
    {
        str = tstrsub(pwd, strlen(home) + 1, strlen(pwd) - strlen(home) - 1);
        str = fttt_strjoin("~/", str);
    }
    free(pwd);
    printf("    CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[3m\n\n", exam->level);
    printf("   CURRENT PROJECT\n   ---> \x1B[33m%s      \x1B[37m\n   for :\x1B[32m %.2f\x1B[37m XP 🧪 \n\n", exam->nameofex, exam->xpperex);
    printf("\x1B[5mAssignement\x1B[0;m  : %s/rendu/", str);
    printf("\n\x1B[5m\x1B[37mSubject\x1B[0;m      : %s/subject.en.txt\n\n\n\x1B[37m", str);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mexit\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time\n\n");
    display_end(exam->depart);
    free(str);
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
