#include <unistd.h>

void	ft_swapcases(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_swapcases(argv[1]);
	write(1, "\n", 1);
	return (0);
}