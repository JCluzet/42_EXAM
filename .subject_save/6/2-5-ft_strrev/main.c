#include <stdio.h>

char	*ft_strrev(char *str);

int	main(int ac, char **argv)
{
	char *s = argv[1];
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}
