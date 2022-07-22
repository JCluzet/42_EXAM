/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:13:03 by jcluzet           #+#    #+#             */
/*   Updated: 2022/07/22 18:09:20 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"
#include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
#include <string.h>
#define LIMIT 5
#define NEW02 0

int fstrlen(char *cmd)
{
    int i;
    while (cmd[i])
        i++;
    return (i);
}

char    *fstrjoin(char *remains, char *buffer)
{
    char *array;
    unsigned int size;
    int i;
    int j;

    if (!remains && !buffer)
        return (NULL);
    size = fstrlen(remains) + fstrlen(buffer);
    if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    i = 0;
    j = 0;
    if (remains)
    {
        while (remains[i])
        {
            array[j] = remains[i];
            i++;
            j++;
        }
        i = 0;
    }
    while (buffer[i])
    {
        array[j] = buffer[i];
        i++;
        j++;
    }
    array[size] = '\0';
    // free((void *)remains);
    return (array);
}


int main(int argc, char **argv)
{
    t_exam examm;
    remove("a.out");
    system("bash .system/maj.sh");
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
    int april;
    int hour;
    int ret;
    exam->start = -10;
    blank();
    printf("\x1B[31m!!\x1B[37m 42 decided to revise different aspects of the exam \x1B[31m!!\x1B[37m\n");
    printf("  └--> starting \x1B[32mApril 15, 2022\x1B[37m. (here & at 42)\n\n");
    printf("  The \x1B[32mfollowing changes\x1B[37m will also be effective on 42_EXAM :\n");
    printf("                 └--> At 42, exam will be done only on Linux. (42_EXAM will continue to run on Mac & Linux).\n");
    printf("                 └--> The exercises of the Exam Rank 03 are deleted (micro_paint, mini_paint).\n");
    printf("                 └--> The exercises of the Exam Rank 02 are moved to Exam Rank 03 (get_next_line, printf).\n");
    printf("                 └--> The exercises of the Exam Rank 02 will contain some of the exercice in the pool's final exam.\n\n");
    printf("  -> Please select a exam type to continue.\n");
    printf("             └--> \x1B[32m1\x1B[37m : \x1B[32mNEW\x1B[37m exam after April 15\n");
    printf("             └--> \x1B[32m2\x1B[37m : \x1B[31mOLD\x1B[37m exam before April 15\n");
    printf("\nEnter your choice : (1 or 2)\n");
    buf = readline("");
    // while choice is not 1 or 2
    while (buf[0] != '1' && buf[0] != '2')
    {
        printf("\x1B[31m!!\x1B[37m Please enter a valid choice.\x1B[31m!!\x1B[37m\n");
        buf = readline("");
    }
    if (buf[0] == '1')
        april = 1;
    else
        april = 0;
    // ch = getchar();
    blank();
    printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to try?\n\n\n     | PISCINE PART |\n      --------------\n\n     \x1B[32m1\x1B[37m - Exam week 1\n     \x1B[32m2\x1B[37m - Exam week 2\n     \x1B[32m3\x1B[37m - Exam week 3   \x1B[31mUNAVAILABLE\x1B[37m\n     \x1B[32m4\x1B[37m - Exam FINAL    \x1B[31mUNAVAILABLE\x1B[37m\n\nExam 3 and 4 are not available to piscine exam to ensure 42 selection equality.\n\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m5\x1B[37m - Exam Rank 02\n     \x1B[32m6\x1B[37m - Exam Rank 03\n     \x1B[32m7\x1B[37m - Exam Rank 04\n     \x1B[32m8\x1B[37m - Exam Rank 05\n\n     |  BONUS PART  |\n      --------------\n\n     \x1B[32m9\x1B[37m - Student Specific Exam\n\nEnter your choice: \n");
    ret = get_next_line(0, &buf);
    while ((atoi(buf) < 1 || atoi(buf) > 2) && atoi(buf) != 5 && atoi(buf) != 6 && atoi(buf) != 7 && atoi(buf) != 8 && atoi(buf) != 9)
    {
        printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 1,2,5,6,7,8, 9\n");
        ret = get_next_line(0, &buf);
    }
    exam->exam_type = atoi(buf);

    if (april)
    {
        if (exam->exam_type == 5 && NEW02 == 1)
        {
                blank();
    printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to try?\n\n\n     | PISCINE PART |\n      --------------\n\n     \x1B[32m1\x1B[37m - Exam week 1\n     \x1B[32m2\x1B[37m - Exam week 2\n     \x1B[32m3\x1B[37m - Exam week 3   \x1B[31mUNAVAILABLE\x1B[37m\n     \x1B[32m4\x1B[37m - Exam FINAL    \x1B[31mUNAVAILABLE\x1B[37m\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m5\x1B[37m - Exam Rank 02\n     \x1B[32m6\x1B[37m - Exam Rank 03\n     \x1B[32m7\x1B[37m - Exam Rank 04\n     \x1B[32m8\x1B[37m - Exam Rank 05\n\n     |  BONUS PART  |\n      --------------\n\n     \x1B[32m9\x1B[37m - Student Specific Exam\n\nEnter your choice: \n");
            printf("\n\x1B[31m\x1B[37mSorry, the NEW ExamRank02 is on working (estimate release : 25 may 2022)....\x1B[31m\x1B[37m\n");
            // sleep (3);
                            // blank();
    // printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to test?\n\n\n     | PISCINE PART |\n      --------------\n\n     \x1B[32m1\x1B[37m - Exam week 1\n     \x1B[32m2\x1B[37m - Exam week 2\n     \x1B[32m3\x1B[37m - Exam week 3   \x1B[31mSOON\x1B[37m\n     \x1B[32m4\x1B[37m - Exam FINAL    \x1B[31mSOON\x1B[37m\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m5\x1B[37m - Exam Rank 02\n     \x1B[32m6\x1B[37m - Exam Rank 03\n     \x1B[32m7\x1B[37m - Exam Rank 04\n     \x1B[32m8\x1B[37m - Exam Rank 05\n\n     |  BONUS PART  |\n      --------------\n\n     \x1B[32m9\x1B[37m - Student Specific Exam\n\nEnter your choice: \n");
            // buf = readline("");
    ret = get_next_line(0, &buf);
    while ((atoi(buf) < 1 || atoi(buf) > 2) && atoi(buf) != 6 && atoi(buf) != 7 && atoi(buf) != 8 && atoi(buf) != 9)
    {
        printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 1,2,6,7,8, 9\n");
        ret = get_next_line(0, &buf);
    }
        }
        if (exam->exam_type == 6)
        {
              exam->exam_type = 5;
            april = 0;
        }
    }
    if (exam->exam_type == 1 || exam->exam_type == 2)
    {
        exam->xpperex = 12.5;
        exam->exbylvl = 2;
        hour = 4;
        exam->trace = 0;
    }
    if (exam->exam_type == 5 && !april)
    {
        exam->xpperex = 50.0;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 1;
    }
    if (exam->exam_type == 5 && april)
    {
        exam->xpperex = 25.0;
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
        exam->xpperex = 33.3;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 0;
    }
    if (exam->exam_type == 9) // Specific exam
    {
        blank();
        printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to try?\n\n\n     | PISCINE PART |\n      --------------\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m0\x1B[37m - \x1B[32mNEW\x1B[37m Exam Rank 02 \n\n     \x1B[32m1\x1B[37m - Exam Rank 02 -> INTER.c\n\n     \x1B[32m2\x1B[37m - Exam Rank 02 -> UNION.c\n\n     \x1B[32m3\x1B[37m - Exam Rank 02 -> GET_NEXT_LINE.c\n\n     \x1B[32m4\x1B[37m - Exam Rank 02 -> FT_PRINTF.c\n\n     \x1B[32m5\x1B[37m - Exam Rank 03 -> MICRO_PAINT.c\n\n     \x1B[32m6\x1B[37m - Exam Rank 03 -> MINI_PAINT.c\n\n     \x1B[32m7\x1B[37m - Exam Rank 04 -> MICROSHELL.c\n\n     \x1B[32m8\x1B[37m - Exam Rank 05 -> CPP_MODULE00\n\n     \x1B[32m9\x1B[37m - Exam Rank 05 -> CPP_MODULE01\n\n     \x1B[32m10\x1B[37m - Exam Rank 05 -> CPP_MODULE02\n\nEnter your choice: \n");
        ret = get_next_line(0, &buf);
        while (atoi(buf) < 0 || atoi(buf) > 10)
        {
            printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 0,1,2,3,4,5,6,7,8,9,10\n");
            ret = get_next_line(0, &buf);
        }
        exam->exam_type = atoi(buf);
        exam->xpperex = 100.00;
        exam->exbylvl = 1;
        hour = 3;
        exam->trace = 1;
        if (exam->exam_type == 0)
        {
            blank();
            printf("\x1B[37m  42EXAM | Made with \x1B[32m♥\x1B[37m by \x1B[32mjcluzet\x1B[37m\n\n\n Which exam would you like to try?\n\n\n     | PISCINE PART |\n      --------------\n\n     | STUDENT PART |\n      --------------\n\n     \x1B[32m0\x1B[37m - first-word");
            printf("\n     \x1B[32m1\x1B[37m - fizzbuzz");
            printf("\n     \x1B[32m2\x1B[37m - ft_strcpy");
            printf("\n     \x1B[32m3\x1B[37m - ft_strlen");
            printf("\n     \x1B[32m4\x1B[37m - ft_swap");
            printf("\n     \x1B[32m5\x1B[37m - putstr");
            printf("\n     \x1B[32m6\x1B[37m - repeat_alpha");
            printf("\n     \x1B[32m7\x1B[37m - rev_print");
            printf("\n     \x1B[32m8\x1B[37m - rot_13");
            printf("\n     \x1B[32m9\x1B[37m - rotone");
            printf("\n     \x1B[32m10\x1B[37m - searchandreplace");
            printf("\n     \x1B[32m11\x1B[37m - ulstr");
            printf("\n\n          SECOND PART");

            printf("\n     \x1B[32m12\x1B[37m - alpha_mirror");
            printf("\n     \x1B[32m13\x1B[37m - do_op");
            printf("\n     \x1B[32m14\x1B[37m - ft_atoi");
            printf("\n     \x1B[32m15\x1B[37m - ft_strcmp");
            printf("\n     \x1B[32m16\x1B[37m - ft_strcspn");
            printf("\n     \x1B[32m17\x1B[37m - inter");
            printf("\n     \x1B[32m18\x1B[37m - last_word");
            printf("\n     \x1B[32m19\x1B[37m - is_power_of_2");
            printf("\n     \x1B[32m20\x1B[37m - max");
            printf("\n     \x1B[32m21\x1B[37m - ft_strdup");
            
            printf("\n\nEnter your choice: \n");
            ret = get_next_line(0, &buf);
            while (atoi(buf) < 0 || atoi(buf) > 21)
            {
                printf("   └--> \x1B[31mError\x1B[37m | Unknown argument, enter number 1 to 21\n");
                ret = get_next_line(0, &buf);
            }
            if (atoi(buf) < 12 && atoi(buf) >= 0)
                exam->folder_num = 20;
            if (atoi(buf) < 22 && atoi(buf) > 11)
                exam->folder_num = 21;
            if (atoi(buf) == 0)
                system("bash .system/specific.sh .subject/20 first_word");
            if (atoi(buf) == 1)
                system("bash .system/specific.sh .subject/20 fizzbuzz");
            if (atoi(buf) == 2)
                system("bash .system/specific.sh .subject/20 ft_strcpy");
            if (atoi(buf) == 3)
                system("bash .system/specific.sh .subject/20 ft_strlen");
            if (atoi(buf) == 4)
                system("bash .system/specific.sh .subject/20 ft_swap");
            if (atoi(buf) == 5)
                system("bash .system/specific.sh .subject/20 putstr");
            if (atoi(buf) == 6)
                system("bash .system/specific.sh .subject/20 repeat_alpha");
            if (atoi(buf) == 7)
                system("bash .system/specific.sh .subject/20 rev_print");
            if (atoi(buf) == 8)
                system("bash .system/specific.sh .subject/20 rot_13");
            if (atoi(buf) == 9)
                system("bash .system/specific.sh .subject/20 rotone");
            if (atoi(buf) == 10)
                system("bash .system/specific.sh .subject/20 searchandreplace");
            if (atoi(buf) == 11)
                system("bash .system/specific.sh .subject/20 ulstr");
            if (atoi(buf) == 12)
                system("bash .system/specific.sh .subject/21 alpha_mirror");
            if (atoi(buf) == 13)
                system("bash .system/specific.sh .subject/21 do_op");
            if (atoi(buf) == 14)
                system("bash .system/specific.sh .subject/21 ft_atoi");
            if (atoi(buf) == 15)
                system("bash .system/specific.sh .subject/21 ft_strcmp");
            if (atoi(buf) == 16)
                system("bash .system/specific.sh .subject/21 ft_strcspn");
            if (atoi(buf) == 17)
                system("bash .system/specific.sh .subject/21 inter");
            if (atoi(buf) == 18)
                system("bash .system/specific.sh .subject/21 last_word");
            if (atoi(buf) == 19)
                system("bash .system/specific.sh .subject/21 is_power_of_2");
            if (atoi(buf) == 20)
                system("bash .system/specific.sh .subject/21 max");
            if (atoi(buf) == 21)
                system("bash .system/specific.sh .subject/21 ft_strdup");
        }
        else 
        {
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
        if (exam->exam_type == 8)
        {
            exam->folder_num = 15;
        }
        if (exam->exam_type == 9)
        {
            exam->folder_num = 16;
        }
        if (exam->exam_type == 10)
        {
            exam->folder_num = 17;
        }
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
    if (exam->exam_type == 5 && !april)
        exam->folder_num = 11;
    if (exam->exam_type == 5 && april)
        exam->folder_num = 20;
    if (exam->exam_type == 6)
        exam->folder_num = 13;
    if (exam->exam_type == 7)
        exam->folder_num = 14;
    if (exam->exam_type == 8)
        exam->folder_num = 15;
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
        if(!buf)
        {
            header(exam);
            printf("\n\033[32m$ ➜\033[00m Ctrl+D \n");
            printf("     └--> \x1B[31mError\x1B[37m: Please use finish to exit\n");
            continue;
        }
        add_history(buf);
        if (dispatcheur(exam, buf) == -1)
        {
            header(exam);
            printf("\n\033[32m$ ➜\033[00m  %s \n", buf);
            printf("     └--> \x1B[31mError\x1B[37m | type \x1B[32mhelp\x1B[37m/\x1B[32mgrademe\x1B[37m/\x1B[32mtime\x1B[37m/\x1B[32mfinish\x1B[37m/\x1B[32mfeedback\x1B[37m or start working on a NEW window.\n");
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
        printf("Time is now removed ;)\n");
        sleep (2);
    }
    if (ft_strcmp(buf, "feedback") == 0)
    {
        printf("\033[37mEnter your \033[32mfeedback\033[37m:  ");
        char *buf2 = readline("");
        if (buf2[0] != '\0')
        {
            printf("\033[37mWould you like to be contacted regarding this feedback? (y/n)\033[00m\n");
            char *buf3 = readline("");
            char *str = NULL;
            if (buf3[0] == 'y')
            {
                str = fstrjoin("bash .system/feedback.sh ", buf2);
                str = fstrjoin(str, " yes");
                // printf("YEre command : %s\n", str);
                system(str);
                // system("pwd");
            }
            else 
            {
                str = fstrjoin("bash .system/feedback.sh ", buf2);
                str = fstrjoin(str, " no");
                system(str);
            }
            printf("\033[32mYour feedback has just been sent ❤️ \033[00m\n");
        }
        else 
        {
            printf("\033[31mFeedback is empty.\033[00m\n");
        }
        return(0);
    }
    if (ft_strcmp(buf, "time") == 0)
        return (time_left(exam->depart, exam));
    if (ft_strcmp(buf, "finish") == 0)
    {
        printf("\n\n\x1B[31m   ⚠️  Warning: You're about to END your exam.\n   \x1B[32m%.02f%%\x1B[31m will be you're final score and you will not be able to go back.\x1B[37m\n\n", exam->level);
        printf("      > Enter 'y' to confirm exit\n\n");
        scanf("%c", &ch);
        if (ch == 'y')
        {
            blank();
            printf("🎉 You finish the exam with a score of \x1B[32m%.02f\x1B[37m %% and \x1B[31m%d fail\x1B[37m\n", exam->level, exam->nbfail);
            time(&arrivee);
            seconds = difftime(exam->depart, arrivee);
            hours = seconds / 3600;
            minutes = (seconds - (hours * 3600)) / 60;
            sec = seconds - (hours * 3600) - (minutes * 60);
            printf("\n\x1B[37mHere is your remaining time: \x1B[32m%d H %d M %d S\n\x1B[37m", hours, minutes, sec);
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

char *strsub(char *s, unsigned int start, size_t len)
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

char *ftt_strjoin(char *str, char *str1)
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

void header(t_exam *exam)
{
    blank();
    char *str;
    // get the pwd start with ~/
    char *pwd = getcwd(NULL, 0);
    char *home = getenv("HOME");
    // if home is in pwd, replace it by ~
    if (strstr(pwd, home) != NULL)
    {
        str = strsub(pwd, strlen(home) + 1, strlen(pwd) - strlen(home) - 1);
        str = ftt_strjoin("~/", str);
    }
    else
        str = pwd;
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
    free(str);
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
