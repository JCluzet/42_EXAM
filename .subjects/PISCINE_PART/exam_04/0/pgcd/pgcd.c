#include <stdio.h>
#include <stdlib.h>

int		pgcd(unsigned int nb, unsigned int nb2)
{
	int i;

	i = nb;
	while (i > 0)
	{
		if (nb % i == 0 && nb2 % i == 0)
			return (i);
		i--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", pgcd(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
	return (0);
}
