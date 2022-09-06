#include <unistd.h>

void	wdmatch(char *s1, char *s2);

int		main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
