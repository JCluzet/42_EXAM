#include <stdio.h>
#include <stdlib.h>

void	ft_sorter(int *k, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc-1)
	{
		j = i;
		while (j < argc-1)
		{
			if (k[i] > k[j])
			{
				tmp = k[j];
				k[j] = k[i];
				k[i] = tmp;
			}
			j++;
		}
		i++;
	}	
}

int	main(int argc, char **argv)
{
	int	*i;
	int	j;

	j = 0;
	i = (int *)malloc(sizeof(int)*(argc-1));
	if (!i)
		return (0);
	while(j < argc-1)
	{
		i[j] = atoi(argv[j+1]);
		j++;
	}
	j = 0;
	while (j < argc-1)
	{
		printf("%i\n", i[j]);
		j++;
	}
	ft_sorter(i, argc);
	printf("\n");
	j = 0;
	while (j < argc-1)
	{
		printf("%i\n", i[j]);
		j++;
	}
	free(i);
	return (0);
}
