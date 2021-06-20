/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:13:03 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/20 19:41:02 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exam.h"
# define LIMIT   5

int main(int argc, char **argv)
{
	t_exam examm;
	remove("a.out");
    examm.midlev = 0;
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
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\x1B[37m          42EXAM\n\n Quel examen de piscine souhaitez vous tester ?\n\n  \x1B[32m1\x1B[37m - Exam semaine 1\n  \x1B[32m2\x1B[37m - Exam semaine 2   \x1B[31mSOON\x1B[37m\n  \x1B[32m3\x1B[37m - Exam semaine 3   \x1B[31mSOON\x1B[37m\n  \x1B[32m4\x1B[37m - Exam FINAL       \x1B[31mSOON\x1B[37m\n\nEntrez votre choix : \n");
    ret = get_next_line(0, &buf);
    while (atoi(buf) < 1 || atoi(buf) > 1)
	{
		printf("   └--> Error | Argument inconnu, entrez un chiffre de 1 à 1\n");
		ret = get_next_line(0, &buf);
	}
    exam->exam_type = atoi(buf);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\x1B[37mL'exam \x1B[32m%d\x1B[37m dure 2 heures.\n\nGardez ce terminal dans un coin de votre ecran, et travaillez sur une nouvelle fenetre.\n\n       Quand vous etes pret, cliquez sur la touche return.", exam->exam_type);
    scanf("%c",&ch);
	int cpt = LIMIT;
    time_t prv;
    time_t crt = time(NULL);

    while(cpt > 0)
    {
        prv = crt;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
			printf("   └--> Error | Argument inconnu, tapez help \n");
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nVous terminez l'examen avec une note de \x1B[32m%.02f\x1B[37m %%\n", exam->level);
            time(&arrivee);
            seconds = difftime(exam->depart, arrivee);
            hours = seconds / 3600;
            minutes = (seconds - (hours * 3600)) / 60;
            sec = seconds - (hours * 3600) - (minutes * 60);
            printf("\n\x1B[37mVoici votre temps restant : \x1B[32m%d H %d M %d S\n\n\x1B[37m", hours, minutes, sec);
        system("make reset");
        exit(0);
    }
    if (ft_strcmp(buf, "push") == 0)
    {
        time(&exam->timestart);
        if (exam->timeend <= exam->timestart)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\x1B[31mÊtes vous certain de vouloir faire corriger votre level ? \x1B[37m\n   > Entrez 'y' pour continuer\n\n");
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
                printf("\n Vous devez patienter \x1B[31m %d minutes et %d secondes \x1B[37m pour faire corriger votre level\n\n", minfail, secondfail);
            }
            else
                printf("\n Vous devez patienter \x1B[31m %d secondes \x1B[37m pour faire corriger votre level\n\n", secondfail);
        return(0);
        }
    }
	return (-1);
}

int    help(t_exam *exam)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\x1B[32mpush\x1B[37m pour rendre l'exercice");
    printf("\n\x1B[32mexit\x1B[37m pour abandonner");
    printf("\n\x1B[32mtime\x1B[37m pour connaitre le temps restant\n\n");
    printf("\n\x1B[32m   EXPLICATION : \x1B[37m");
    printf("\n\n     Vous devez travailler à partir d'une nouvelle fenetre afin de garder celle ci \x1B[32maccessible\x1B[37m.");
    printf("\n     Un sujet a été généré au nom de \x1B[32msubject.en.txt\x1B[37m.");
    printf("\n     Vous devez rédiger votre rendu dans le dossier \x1B[32mrendu\x1B[37m.");
    printf("\n     Une fois terminé, vous rendez votre projet avec \x1B[32mpush\x1B[37m.");
    printf("\n     Si votre rendu est validé, vous passez au prochain niveau.");
    printf("\n     Sinon, vous devez recommencer.");
    printf("\n     Attention : Plus vous tenter de faire corriger un même projet, plus vous devrez attendre pour le faire \x1B[32mcorriger\x1B[37m.\n\n");
    return(0);
}

void header(t_exam *exam)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n       Note actuelle : \x1B[32m%.2f\x1B[37m %%\n\n", exam->level);
    printf("\x1B[32mhelp\x1B[37m pour obtenir de l'aide");
    printf("\n\x1B[32mpush\x1B[37m pour rendre l'exercice");
    printf("\n\x1B[32mexit\x1B[37m pour abandonner");
    printf("\n\x1B[32mtime\x1B[37m pour connaitre le temps restant\n\n");
    display_end(exam->depart);
    // time_left(exam->depart);
}

int time_left(time_t depart, t_exam *exam)
{
    time_t arrivee;
    float seconds;
    int sec;
    int hours;
    int minutes;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n     Note actuelle : \x1B[32m%.02f\x1B[37m %%\n", exam->level);
    printf("\n\x1B[32mpush\x1B[37m pour rendre l'exercice");
    printf("\n\x1B[32mhelp\x1B[37m pour obtenir de l'aide");
    printf("\n\x1B[32mexit\x1B[37m pour abandonner");
    printf("\n\x1B[32mtime\x1B[37m pour le temps restant\n\n");

    time(&arrivee);
    seconds = difftime(depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mTemps restant : \x1B[32m%d H %d M %d S\n\n\x1B[37m", hours, minutes, sec);
    return(0);
}

void display_end(time_t depart)
{
    struct tm * t;

    t = localtime(&depart);
    printf("Heure de fin : \x1B[32m%02uh%02u\x1B[37m\n", t->tm_hour, t->tm_min);
}

void s_sleep(int seconds) {
    /* Init. */
    time_t start_time = 0;
    time_t current_time = 0;

    /* Operate. */
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
