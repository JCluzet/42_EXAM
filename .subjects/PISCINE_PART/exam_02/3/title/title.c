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

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	title_case(char *str)
{
	int		start_of_word = 1;

	while (*str)
	{
		if (is_alpha(*str) && start_of_word)
		{
			ft_putchar(to_upper(*str));
			start_of_word = 0;
		}
		else
		{
			ft_putchar(*str);
			if (*str == ' ')
				start_of_word = 1;
		}
		str++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		title_case(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}

