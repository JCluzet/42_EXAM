/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:13:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/02 04:11:50 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"
# include <errno.h>
# include <string.h>
# define LIMIT   5

int main(int argc, char **argv)
{
	t_exam examm;
	remove("a.out");
    examm.midlev = 0;
    examm.nbfail = 0;
    examm.failuretime = 0.0;
    examm.timeend = 0;

	if (argc == 1)
		start(&examm);
}

int	start(t_exam *exam)
{
    char				*buf;
    char    ch;
    int ret;
    exam->start = -10;
    blank();
    printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n\n Which exam would you like to test?\n\n     \x1B[32m1\x1B[37m - Exam week 1\n     \x1B[32m2\x1B[37m - Exam week 2   \x1B[31mSOON\x1B[37m\n     \x1B[32m3\x1B[37m - Exam week 3   \x1B[31mSOON\x1B[37m\n     \x1B[32m4\x1B[37m - Exam FINAL    \x1B[31mSOON\x1B[37m\n\nEnter your choice: \n");
    ret = get_next_line(0, &buf);
    while (atoi(buf) < 1 || atoi(buf) > 1)
	{
		printf("   └--> Error | Unknown argument, enter a number from 1 to 1\n");
		ret = get_next_line(0, &buf);
	}
    exam->exam_type = atoi(buf);
    blank();
    printf("\n\x1B[32m        EXPLANATION : \x1B[37m");
    printf("\n\n     ⚠️  You have to work from a new window to keep this one \x1B[32mavailable\x1B[37m\n");
    printf("\n     📝 A random subject named \x1B[32msubject.en.txt\x1B[37m will be generated");
    printf("\n         > You must write your project in the folder : \x1B[32mrendu\x1B[37m");
    printf("\n\n     🎓 Once completed, you can push/correct your project with : \x1B[32mpush\x1B[37m");
    printf("\n         If your level is validated, you move on to the next level 🎉");
    printf("\n         If not, you have to start again ❌");
    printf("\n\n     ⌛️ Warning: The more you try to get the same project corrected, \n     the longer you will have to wait to get it \x1B[32mcorrected\x1B[37m.\n\n");
    printf("\n\x1B[37m     Exam \x1B[32m%d\x1B[37m take 2 hours.", exam->exam_type);
	printf("\n\n       > When you are ready, click on the\n       \x1B[37mreturn button to start the exam\x1B[37m.");
    scanf("%c",&ch);
	int cpt = LIMIT;
    time_t prv;
    time_t crt = time(NULL);

    while(cpt > 0)
    {
        prv = crt;
		blank();
        printf("%d\n", cpt);
        do
        {
            crt = time(NULL);
        } while(crt == prv);
		{
        cpt--;
		}
    }
    exam->depart = time(&exam->depart) + 7200;
    header(exam);
    if (exam->exam_type == 1)
        exam->folder_num = 1;
    if (exam->exam_type == 2)
        exam->folder_num = 3;
    if (exam->exam_type == 3)
        exam->folder_num = 5;
    if (exam->exam_type == 4)
        exam->folder_num = 7;
    generate_subject(exam);
    instruction(exam);
    return 0;
}

void instruction(t_exam *exam)
{
    char				*buf;
    int ret;

    ret = get_next_line(0, &buf);
    while (1)
	{
		if (dispatcheur(exam, buf) == -1)
        {
            header(exam);
            printf("%s\n", buf);
			printf("   └--> Error | Unknown argument, type help \n");
        }
        ret = get_next_line(0, &buf);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


int		dispatcheur(t_exam *exam, char *buf)
{
    char ch;
    time_t arrivee;
    int secondfail;
    int minfail;
    float seconds;
    int sec;
    int hours;
    int minutes;

	if (ft_strcmp(buf, "help") == 0)
		return (help(exam));
    if (ft_strcmp(buf, "time") == 0)
		return (time_left(exam->depart, exam));
    if (ft_strcmp(buf, "exit") == 0)
    {
        blank();
        printf("You finish the exam with a score of \x1B[32m%.02f\x1B[37m %% and \x1B[31m%d fail\x1B[37m\n", exam->level, exam->nbfail);
            time(&arrivee);
            seconds = difftime(exam->depart, arrivee);
            hours = seconds / 3600;
            minutes = (seconds - (hours * 3600)) / 60;
            sec = seconds - (hours * 3600) - (minutes * 60);
            printf("\n\x1B[37mHere is your remaining time: \x1B[32m%d H %d M %d S\n\n\x1B[37m", hours, minutes, sec);
        system("make reset");
        exit(0);
    }
    if (ft_strcmp(buf, "push") == 0)
    {
        time(&exam->timestart);
        if (exam->timeend <= exam->timestart)
        {
            blank();
            printf("\x1B[31mAre you sure you want to have your exercise corrected?  \x1B[37m\n   > Enter 'y' to continue\n\n");
            scanf ("    %c", &ch);
            if (ch == 'y')
            {
                push(exam);
                return(0);
            }
            else
            {
                header(exam);
                return(0);
            }
        }
        else
        {
            secondfail = difftime(exam->timeend, exam->timestart);
            if (secondfail > 60)
            {
                minfail = secondfail / 60;
                secondfail = secondfail - (minfail * 60);
                printf("\n You must wait\x1B[31m %dmin and %dsec \x1B[37m to have your level corrected\n\n", minfail, secondfail);
            }
            else
                printf("\n You must wait \x1B[31m %dsec \x1B[37m to have your level corrected\n\n", secondfail);
        return(0);
        }
    }
	return (-1);
}

int    help(t_exam *exam)
{
    blank();
    printf("\n\x1B[32mpush\x1B[37m to have your project corrected");
    printf("\n\x1B[32mexit\x1B[37m to abandon");
    printf("\n\x1B[32mtime\x1B[37m to know the remaining time\n\n");
    printf("\n\x1B[32m        EXPLANATION : \x1B[37m");
    printf("\n\n     ⚠️  You have to work from a new window to keep this one \x1B[32mavailable\x1B[37m\n");
    printf("\n     📝 A random subject named \x1B[32msubject.en.txt\x1B[37m has been generated");
    printf("\n         > You must write your project in the folder : \x1B[32mrendu\x1B[37m");
    printf("\n\n     🎓 Once completed, you can push/correct your project with : \x1B[32mpush\x1B[37m");
    printf("\n         If your level is validated, you move on to the next level 🎉");
    printf("\n         If not, you have to start again ❌");
    printf("\n\n     ⌛️ Warning: The more you try to get the same project corrected, \n     the longer you will have to wait to get it \x1B[32mcorrected\x1B[37m.\n\n");
    return(0);
}

void header(t_exam *exam)
{
    FILE* fichier = NULL;
    char chaine[30] = "cannot detect name";

    fichier = fopen(".system/name", "r");
    if (fichier != NULL)
    {
        fgets(chaine, 30, fichier);
        fclose(fichier);
    }
    else
        printf("\nOh dear, something went wrong with read()! %s\n", strerror(errno));
    blank();
    printf("      Current Grade : \x1B[32m%.2f\x1B[37m %%\n", exam->level);
    printf("         Working on : \x1B[32m%s\x1B[37m\n", chaine);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mpush\x1B[37m to get corrected");
    printf("\nType \x1B[32mexit\x1B[37m to left");
    printf("\nType \x1B[32mtime\x1B[37m to know the remaining time\n\n");
    display_end(exam->depart);
}

int time_left(time_t depart, t_exam *exam)
{
    time_t arrivee;
    float seconds;
    int sec;
    int hours;
    int minutes;

    blank();
    printf("      Current Grade : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
    printf("\n\x1B[32mhelp\x1B[37m to get some help");
    printf("\n\x1B[32mpush\x1B[37m to get corrected");
    printf("\n\x1B[32mexit\x1B[37m to left");
    printf("\n\x1B[32mtime\x1B[37m to know the remaining time\n\n");

    time(&arrivee);
    seconds = difftime(depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mTime left : \x1B[32m%d H %d M %d S\n\n\x1B[37m", hours, minutes, sec);
    return(0);
}

void display_end(time_t depart)
{
    struct tm * t;

    t = localtime(&depart);
    printf("Ending time : \x1B[32m%02uh%02u\x1B[37m\n", t->tm_hour, t->tm_min);
}

void s_sleep(int seconds) {
    time_t start_time = 0;
    time_t current_time = 0;

    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}

void    blank(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
