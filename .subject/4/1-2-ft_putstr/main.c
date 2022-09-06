#include <stdio.h>

void	ft_putstr(char *str);

int main (int argc, char **argv)
{
	(void)argc;
	ft_putstr(argv[1]);
	return (0);
}
