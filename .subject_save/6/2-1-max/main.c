#include <stdio.h>
#include <stdlib.h>

int		max(int *tab, unsigned int len);

int		main(int argc, char **argv)
{
	int	*tab;
	int i = 0;

	if (!(tab = (int*)malloc(sizeof(int) * 3)))
		return (0);
	while (i < argc-1)
	{
		tab[i] = atoi(argv[i+1]);
		i++;
	}
	printf("%d", max(tab, argc-1));
	return (0);
}
