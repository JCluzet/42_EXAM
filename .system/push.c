/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo <jo@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:02:42 by jcluzet           #+#    #+#             */
/*   Updated: 2022/07/07 01:23:17 by jo               ###   ########.fr       */
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
	FILE *filetest;
    if ((filetest = ((fopen(".system/verif/tester.sh", "r")))))
    {
	int n;
	float sec;


	int temp = 0;
	n = rand() % 40 + 11;
    
	#define INTERVAL (0.7 * CLOCKS_PER_SEC)

	
	float i = 0;
	int v = 0;
    clock_t target;
    char spin[] = "\\|/-";
	blank();
	printf ("(10 sec is fast, 20 sec is expected, 50 sec is anormal)\n\nwaiting...\n");
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
    
    // if there is no .system/verif/tester.sh file, it means that the correction can't be done
	system("bash .system/verif/tester.sh");
    printf ("\n");

    }
    else 
    {
        char c = '\0';
        while (c != 'y' && c != 'n')
        {
            printf ("\n\n\nOh no ! There is no correction for this exercice yet !\n");
            printf ("You can exceptionnally validate it by enter y\n (y/n)\n");
            scanf ("%c", &c);
        }
        if (c == 'y')
        {
            system("touch .system/verif/passed");
            printf ("\n");
        }
    }
	FILE *file;
    if ((file = ((fopen(".system/verif/passed", "r")))))
    {
        // system("bash .system/beautiful_grade.sh 0");
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
		generate_subject(exam);
    blank();
		printf("\x1B[32mCongratulation!\x1B[37m Your work as been saved in \x1B[32msuccess/\x1B[37m folder.\n A new subject is now created.\n\n");
    char *str = "42_EXAM";
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
    printf(" \x1B[3m   CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[3m\n\n", exam->level);
    printf("   CURRENT PROJECT\n     \x1B[33m%s      \x1B[37m└->\x1B[32m%.2f\x1B[37mXP \n\n", exam->nameofex, exam->xpperex);
    printf("\e[0mAssignement\x1B[0m:\n ➤ \e[2m%s/rendu/%s\x1B[37m", str, exam->nameofex);


    
    printf("\e[0m\nSubject\x1B[0m:\n ➤ \e[2m%s/subject.en.txt\n\n\e[0m", str);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mfinish\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time");
    printf("\n\x1B[31m NEW \x1B[32mfeedback\x1B[37m to report a problem or questions\n\n");
    display_end(exam->depart);
    if (strstr(pwd, home) != NULL)
        free(str);
    
	exam->failuretime = 0;
	}
	else
	{
        system("bash .system/sendfail.sh");
        // system("bash .system/beautiful_grade.sh");
		printf("\n\x1B[31m <<<<<<<<<< \x1B[1m\x1B[5mFAILURE\033[0;m \x1B[31m>>>>>>>>>> \x1B[37m\n\n");
		s_sleep(3);
        printf ("\n");
		if (exam->trace)
			printf("Normally the traceback is not available for this exam at 42\nbut since it is a training, it is available here :)");
		printf("\n\n\x1B[37mFind the trace in the file \x1B[31m> traceback\x1B[37m\n\n");
    char *str = "42_EXAM";
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
    printf(" \x1B[3m   CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[3m\n\n", exam->level);
    printf("   CURRENT PROJECT\n     \x1B[33m%s      \x1B[37m└->\x1B[32m%.2f\x1B[37mXP \n\n", exam->nameofex, exam->xpperex);
    printf("\e[0mAssignement\x1B[0m:\n ➤ \e[2m%s/rendu/%s\x1B[37m", str, exam->nameofex);


    
    printf("\e[0m\nSubject\x1B[0m:\n ➤ \e[2m%s/subject.en.txt\n\n\e[0m", str);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
    printf("\nType \x1B[32mfinish\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time");
    printf("\n\x1B[31m NEW \x1B[32mfeedback\x1B[37m to report a problem or questions\n\n");
    display_end(exam->depart);
    if (strstr(pwd, home) != NULL)
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
	time(&arrivee);
    seconds = difftime(exam->depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
	printf("\x1B[32mCongratulation!\x1B[37m You have completed the exam %d with \x1B[31m%d fail\x1B[37m and \x1B[32m%dh %dm %ds\x1B[37m left.\nYour work as been saved in success/ folder.\n\n",exam->exam_type, exam->nbfail, hours, minutes, sec);

    char resp;
    printf("\nHey! If you like this project, why don't give us a star on github ? \x1B[31m❤️\x1B[37m \n");
    // enter y to open page on google with the link, or another char to skip
    printf("\x1B[37mOpen 42_EXAM on github ? 😎 (y/n)\n");
    scanf("  %c", &resp);
    // if on linux use xdg-open to open the page, else use open command
    int is_linux = 0;
    #ifdef __linux__
        is_linux = 1;
    #endif
    if (resp == 'y')
    {
        if (is_linux)
            system("xdg-open https://github.com/JCluzet/42_EXAM");
        else
            system("open https://github.com/JCluzet/42_EXAM");
        printf("\nThanks for your contribution! \x1B[31m❤️\x1B[37m \n");
    }
    else
        printf("Maybe an other time.. 😢");
    system("make reset");
    exit(0);
}
