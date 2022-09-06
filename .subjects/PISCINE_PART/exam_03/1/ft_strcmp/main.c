#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_strcmp(av[1], av[2]));
	return (0);
}
