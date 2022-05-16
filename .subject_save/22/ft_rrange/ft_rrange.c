// Passed Moulinette 2019.09.01

#include <stdlib.h>

int		absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);

	if (start > end)
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
	return (array);
}

//-----------------------------------------------------
// #include <stdio.h>

// int		main(void)
// {
// 	int start = 0;
// 	int end = -3;

// 	int *arr = ft_rrange(start, end);

// 	int i = 0;
// 	while (i < 1 + absolute_value(end - start))
// 	{
// 		printf("%d, ", arr[i]);
// 		++i;
// 	}
// 	printf("\n");
// }