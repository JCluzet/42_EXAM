/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:13:03 by jcluzet           #+#    #+#             */
/*   Updated: 2022/01/24 23:02:53 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"
#include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
#include <string.h>
#define LIMIT 5


int main(int argc, char **argv)
{
    t_exam examm;
    remove("a.out");
    examm.midlev = 0;
    examm.notime = 0;
    examm.nbfail = 0;
    examm.failuretime = 0.0;
    examm.timeend = 0;
    examm.level = 0;

    if (argc == 1)
        start(&examm);
}

int start(t_exam *exam)
{
    char *buf;
    char ch;
    int hour;
    int ret;
    exam->start = -10;
    blank();
    printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to test?\n\n\n     | PISCINE PART |\n      --------------\n\n     \x1B[32m1\x1B[37m - Exam week 1\n     \x1B[32m2\x1B[37m - Exam week 2\n     \x1B[32m3\x1B[37m - Exam week 3   \x1B[31mSOON\x1B[37m\n     \x1B[32m4\x1B[37m - Exam FINAL    \x1B[31mSOON\x1B[37m\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m5\x1B[37m - Exam Rank 02\n     \x1B[32m6\x1B[37m - Exam Rank 03\n     \x1B[32m7\x1B[37m - Exam Rank 04\n\n     |  BONUS PART  |\n      --------------\n\n     \x1B[32m8\x1B[37m - Student Specific Exam\n\nEnter your choice: \n");
    ret = get_next_line(0, &buf);
    while ((atoi(buf) < 1 || atoi(buf) > 2) && atoi(buf) != 5 && atoi(buf) != 6 && atoi(buf) != 7 && atoi(buf) != 8)
    {
        printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 1,2,5,6,7,8\n");
        ret = get_next_line(0, &buf);
    }
    exam->exam_type = atoi(buf);
    if (exam->exam_type == 1 || exam->exam_type == 2)
    {
        exam->xpperex = 12.5;
        exam->exbylvl = 2;
        hour = 4;
        exam->trace = 0;
    }
    if (exam->exam_type == 5)
    {
        exam->xpperex = 50.0;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 1;
    }
    if (exam->exam_type == 6 || exam->exam_type == 7)
    {
        exam->xpperex = 100.0;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 1;
    }
    if (exam->exam_type == 8)
    {
        blank();
        printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to test?\n\n\n     | PISCINE PART |\n      --------------\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m1\x1B[37m - Exam Rank 02 -> INTER.c\n\n     \x1B[32m2\x1B[37m - Exam Rank 02 -> UNION.c\n\n     \x1B[32m3\x1B[37m - Exam Rank 02 -> GET_NEXT_LINE.c\n\n     \x1B[32m4\x1B[37m - Exam Rank 02 -> FT_PRINTF.c\n\n     \x1B[32m5\x1B[37m - Exam Rank 03 -> MICRO_PAINT.c\n\n     \x1B[32m6\x1B[37m - Exam Rank 03 -> MINI_PAINT.c\n\n     \x1B[32m7\x1B[37m - Exam Rank 04 -> MICROSHELL.c\n\nEnter your choice: \n");
        ret = get_next_line(0, &buf);
        while (atoi(buf) < 1 || atoi(buf) > 7)
        {
            printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 1,2,3,4,5,6\n");
            ret = get_next_line(0, &buf);
        }
        exam->exam_type = atoi(buf);
        exam->xpperex = 100.00;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 1;
        if (exam->exam_type == 1)
        {
            system("rm -rf .subject/11/union");
            exam->folder_num = 11;
        }
        if (exam->exam_type == 2)
        {
            system("rm -rf .subject/11/inter");
            exam->folder_num = 11;
        }
        if (exam->exam_type == 3)
        {
            system("rm -rf .subject/12/ft_printf");
            exam->folder_num = 12;
        }
        if (exam->exam_type == 4)
        {
            system("rm -rf .subject/12/get_next_line/");
            exam->folder_num = 12;
        }
        if (exam->exam_type == 5)
        {
            system("rm -rf .subject/13/mini_paint");
            exam->folder_num = 13;
        }
        if (exam->exam_type == 6)
        {
            system("rm -rf .subject/13/micro_paint");
            exam->folder_num = 13;
        }
        if (exam->exam_type == 7)
        {
            exam->folder_num = 14;
        }
    }
    else
    {
    if (exam->exam_type == 1)
        exam->folder_num = 1;
    if (exam->exam_type == 2)
        exam->folder_num = 3;
    if (exam->exam_type == 3)
        exam->folder_num = 5;
    if (exam->exam_type == 4)
        exam->folder_num = 7;
    if (exam->exam_type == 5)
        exam->folder_num = 11;
    if (exam->exam_type == 6)
        exam->folder_num = 13;
    if (exam->exam_type == 7)
        exam->folder_num = 14;
    }
    blank();
    printf("\n\x1B[32m        EXPLANATION : \x1B[37m");
    printf("\n\n     ⚠️  You have to work from a new window to keep this one \x1B[32mavailable\x1B[37m\n");
    printf("\n     📝 A random subject named \x1B[32msubject.en.txt\x1B[37m will be generated");
    printf("\n         > You must write your file (example.c) in the folder : \x1B[32mrendu\x1B[37m");
    printf("\n\n     🎓 Once completed, you can push/correct your project with : \x1B[32mgrademe\x1B[37m");
    printf("\n         If your level is validated, you move on to the next level 🎉");
    printf("\n         If not, you have to start again ❌");
    printf("\n\n     ⌛️ Warning: The more you try to get the same project corrected, \n     the longer you will have to wait to get it \x1B[32mcorrected\x1B[37m.\n\n");
    printf("\n     📌 Nice reminder : Here you don't need to use GIT.\n         Remember that during the exam you will have to use it to push your project !\n\n");
    printf("\n\x1B[37m     Exam \x1B[32m%d\x1B[37m take %d hours.", exam->exam_type, hour);
    printf("\n\n       > When you are ready, click on the\n       \x1B[37mreturn button to start the exam\x1B[37m.");
    scanf("%c", &ch);
    int cpt = LIMIT;
    time_t prv;
    time_t crt = time(NULL);

    exam->depart = time(&exam->depart) + hour * 3600;
    generate_subject(exam);
    instruction(exam);
    return 0;
}

void instruction(t_exam *exam)
{
    char *buf;
    int ret;

    header(exam);
    while (1)
    {
        buf = readline("\n\033[32m$ ➜ \033[00m  ");
        if (dispatcheur(exam, buf) == -1)
        {
            header(exam);
            printf("\n\033[32m$ ➜\033[00m  %s \n", buf);
            printf("     └--> \x1B[31mError\x1B[37m | type \x1B[32mhelp\x1B[37m/\x1B[32mgrademe\x1B[37m/\x1B[32mtime\x1B[37m/\x1B[32mexit\x1B[37m or start working on a NEW window.\n");
        }
        else
            add_history(buf);
    }
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

int dispatcheur(t_exam *exam, char *buf)
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
    if (ft_strcmp(buf, "remove_time") == 0)
    {
        exam->notime = 1;
        printf("Time is now removed.\n");
    }
    if (ft_strcmp(buf, "time") == 0)
        return (time_left(exam->depart, exam));
    if (ft_strcmp(buf, "exit") == 0)
    {
        printf("\n\n\x1B[31m   ⚠️  Warning: You're about to END your exam.\n   \x1B[32m%.02f%%\x1B[31m will be you're final score and you will not be able to go back.\x1B[37m\n\n", exam->level);
        printf("      > Enter 'y' to confirm exit\n\n");
        scanf("%c", &ch);
        if (ch == 'y')
        {
            blank();
            printf("🎉 You exit the exam with a score of \x1B[32m%.02f\x1B[37m %% and \x1B[31m%d fail\x1B[37m\n", exam->level, exam->nbfail);
            time(&arrivee);
            seconds = difftime(exam->depart, arrivee);
            hours = seconds / 3600;
            minutes = (seconds - (hours * 3600)) / 60;
            sec = seconds - (hours * 3600) - (minutes * 60);
            printf("\n\x1B[37mHere is your remaining time: \x1B[32m%d H %d M %d S\n\n\x1B[37m", hours, minutes, sec);
            system("make reset");
            exit(0);
            return (0);
        }
        else
        {
            header(exam);
            return (0);
        }
    }
    if (ft_strcmp(buf, "grademe") == 0)
    {
        time(&exam->timestart);
        if (exam->timeend <= exam->timestart || exam->notime)
        {
            printf("\nNice reminder : Here you don't need to use GIT.\nBut remember that during the exam you will have to use it to push your project !\n\n\x1B[31m   ⚠️  Warning: The more you try to get the same project corrected, \n   the longer you will have to wait to get it \x1B[37mcorrected\x1B[37m.\n  \x1B[37m\n      > Enter 'y' to get corrected\n\n");
            scanf("    %c", &ch);
            if (ch == 'y')
            {
                push(exam);
                return (0);
            }
            else
            {
                header(exam);
                return (0);
            }
        }
        else
        {
            secondfail = difftime(exam->timeend, exam->timestart);
            if (secondfail > 60)
            {
                minfail = secondfail / 60;
                secondfail = secondfail - (minfail * 60);
                printf("\n   ⌛️ You must wait\x1B[31m %dmin and %dsec \x1B[37m to have your level corrected\n", minfail, secondfail);
            }
            else
                printf("\n You must wait\x1B[31m  %dsec  \x1B[37mto have your level corrected\n", secondfail);
            return (0);
        }
    }
    return (-1);
}

int help(t_exam *exam)
{
    header(exam);
    printf("\n\x1B[32m        EXPLANATION : \x1B[37m");
    printf("\n\n     ⚠️  You have to work from a new window to keep this one \x1B[32mavailable\x1B[37m\n");
    printf("\n     📝 A random subject named \x1B[32msubject.en.txt\x1B[37m has been generated");
    printf("\n         > You must write %s         directly in the folder : \x1B[32mrendu\x1B[37m", exam->nameofex);
    printf("\n\n     🎓 Once completed, you can push/correct your project with : \x1B[32mgrademe\x1B[37m");
    printf("\n         If your level is validated, you move on to the next level 🎉");
    printf("\n         If not, you have to start again ❌");
    printf("\n\n     ⌛️ Warning: The more you try to get the same project corrected, \n     the longer you will have to wait to get it \x1B[32mcorrected\x1B[37m.\n\n");
    return (0);
}

void header(t_exam *exam)
{
    blank();
    printf("    CURRENT GRADE\n    --- \x1B[32m%.2f%%\x1B[37m ---  \x1B[3m\n\n", exam->level);
    printf("   CURRENT PROJECT\n   ---> \x1B[32m%s      \x1B[37mfor :\x1B[32m %.2f\x1B[37m XP 🧪 \n\n", exam->nameofex, exam->xpperex);
    printf("\nType \x1B[32mhelp\x1B[37m to get some help");
    printf("\nType \x1B[32mgrademe\x1B[37m to get corrected");
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

    header(exam);
    time(&arrivee);
    seconds = difftime(depart, arrivee);
    hours = seconds / 3600;
    minutes = (seconds - (hours * 3600)) / 60;
    sec = seconds - (hours * 3600) - (minutes * 60);
    printf("\n\x1B[37mTime left : \x1B[32m%d H %d M %d S\x1B[37m\n", hours, minutes, sec);
    return (0);
}

void display_end(time_t depart)
{
    struct tm *t;

    t = localtime(&depart);
    printf("Ending time : \x1B[32m%02uh%02u\x1B[37m\n", t->tm_hour, t->tm_min);
}

void s_sleep(int seconds)
{
    time_t start_time = 0;
    time_t current_time = 0;

    start_time = time(NULL);
    while (current_time - start_time + 1 <= seconds)
    {
        current_time = time(NULL);
    }
}

void blank(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
