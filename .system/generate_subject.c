# include "exam.h"
#include <string.h>

int	generate_subject(t_exam *exam)
{
	FILE* fichier = NULL;

	system("mkdir rendu");
	char *str;
	str = malloc(sizeof(char) * 300);
	// sprintf(str, "bash ./system/generatesub.sh %d", exam->folder_num);
	// printf ("HERE > %s\n", str);
	// system(str);

	if (exam->folder_num == 1)
		system("bash .system/generatesub.sh 1");
	if (exam->folder_num == 2)
		system("bash .system/generatesub.sh 2");
	if (exam->folder_num == 3)
		system("bash .system/generatesub.sh 3");
	if (exam->folder_num == 4)
		system("bash .system/generatesub.sh 4");
	if (exam->folder_num == 5)
		system("bash .system/generatesub.sh 5");
	if (exam->folder_num == 6)
		system("bash .system/generatesub.sh 6");
	if (exam->folder_num == 7)
		system("bash .system/generatesub.sh 7");
	if (exam->folder_num == 8)
		system("bash .system/generatesub.sh 8");
	if (exam->folder_num == 9)
		system("bash .system/generatesub.sh 9");
	if (exam->folder_num == 10)
		system("bash .system/generatesub.sh 10");
	if (exam->folder_num == 11)
		system("bash .system/generatesub.sh 11");
	if (exam->folder_num == 12)
		system("bash .system/generatesub.sh 12");
	if (exam->folder_num == 13)
		system("bash .system/generatesub.sh 13");
	if (exam->folder_num == 14)
		system("bash .system/generatesub.sh 14");
	if (exam->folder_num == 15)
		system("bash .system/generatesub.sh 15");
	if (exam->folder_num == 16)
		system("bash .system/generatesub.sh 16");
	if (exam->folder_num == 17)	
		system("bash .system/generatesub.sh 17");
	FILE *plop;
	if ((exam->folder_num < 18) && (exam->folder_num > 14))
	{
		// if folder_num == 15 plop is cpp_module00
		if (exam->folder_num == 15)
			strcpy(exam->nameofex, "cpp_module00");
		if (exam->folder_num == 16)
			strcpy(exam->nameofex, "cpp_module01");
		if (exam->folder_num == 17)
			strcpy(exam->nameofex, "cpp_module02");
	}
	else
	{
		plop = popen("ls .system/verif | grep .c | grep -v subject", "r");
	char buffer[100];
	fgets(buffer, 30, plop);
	pclose(plop);
	int i = 0;
	while (buffer[i])
	{
		exam->nameofex[i] = buffer[i];
		i++;
	}
	exam->nameofex[i] = '\0';
	}
	return (0);
}
