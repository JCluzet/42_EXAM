#include <stdio.h>
#include <stdlib.h>

int     main(int ac, char **av)
{
	int	div;
	int	nbr;

	if (ac == 2)
	{
		div = 2;
		nbr = atoi(av[1]);
		if (nbr <= 1)
		{
			printf("%d ", nbr);
			return (0);
		}
		while (nbr != 1)
		{
			if (nbr % div == 0)
			{
				printf("%d ", div);
				nbr = nbr / div;
				div = 2;
			}
			else
				div++;
		}	
	}
	printf("\n");
	return (0);
}	
