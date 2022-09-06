#include <unistd.h>
#include <stdio.h>

char    *ft_strdup(char *src);

void	test(char *str)
{
	printf("%s = ", str);
	printf("%s | ", ft_strdup(str));
}

int main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
		test(argv[i++]);
	return 0;
}
