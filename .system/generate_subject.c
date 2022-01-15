# include "exam.h"

int	generate_subject(t_exam *exam)
{
	FILE* fichier = NULL;

	system("mkdir rendu");

	if (exam->folder_num == 1)
		system("sh .system/generatesub.sh 1");
	if (exam->folder_num == 2)
		system("sh .system/generatesub.sh 2");
	if (exam->folder_num == 3)
		system("sh .system/generatesub.sh 3");
	if (exam->folder_num == 4)
		system("sh .system/generatesub.sh 4");
	if (exam->folder_num == 5)
		system("sh .system/generatesub.sh 5");
	if (exam->folder_num == 6)
		system("sh .system/generatesub.sh 6");
	if (exam->folder_num == 7)
		system("sh .system/generatesub.sh 7");
	if (exam->folder_num == 8)
		system("sh .system/generatesub.sh 8");
	if (exam->folder_num == 9)
		system("sh .system/generatesub.sh 9");
	if (exam->folder_num == 10)
		system("sh .system/generatesub.sh 10");
	if (exam->folder_num == 11)
		system("sh .system/generatesub.sh 11");
	if (exam->folder_num == 12)
		system("sh .system/generatesub.sh 12");
	if (exam->folder_num == 13)
		system("sh .system/generatesub.sh 13");
	FILE *plop;
	plop = popen("ls .system/verif | grep .c", "r");
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
	return (0);
}
