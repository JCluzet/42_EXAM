// Passed Moulinette 2019.09.01

#include <stdlib.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
{
	int len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';

	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}

//-------------------------------------------------------
// #include <stdio.h>
// #include <limits.h>

// int		main(void)
// {
// 	int d = INT_MIN;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = -13;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = 0;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = 5;
// 	printf("%d =? %s\n", d, ft_itoa(d));

// 	d = INT_MAX;
// 	printf("%d =? %s\n", d, ft_itoa(d));
// }