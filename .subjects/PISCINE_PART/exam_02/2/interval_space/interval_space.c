#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	interval_space(char *str)
{
	int		first_char = 1;

	while (*str)
	{
		if (is_alpha(*str))
		{
			if (!first_char)
			{
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putchar(' ');
			}
			ft_putchar(*str);
			first_char = 0;
		}
		str++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		interval_space(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}

