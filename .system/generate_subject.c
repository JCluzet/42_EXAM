# include "exam.h"
#include <string.h>

int	generate_subject(t_exam *exam)
{
	FILE* fichier = NULL;

	system("mkdir rendu");
	char *str;
	str = malloc(sizeof(char) * 300);

	char* tmp = malloc(sizeof(char) * 300);
	sprintf(tmp, "bash .system/generatesub.sh %d", exam->folder_num); 
	system(tmp);

	FILE *plop;
	if ((exam->folder_num < 18) && (exam->folder_num > 14))
	{
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
