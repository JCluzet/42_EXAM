#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end);

int main(int argc, char **argv)
{
	(void)argc;
	int	arr_len;
	int	*arr;

	arr_len = abs(atoi(argv[2]) - atoi(argv[1]));
	arr = ft_range(atoi(argv[1]), atoi(argv[2]));
	for (int i = 0; i <= arr_len; i += 1)
		printf("%d\n", arr[i]);
	free(arr);
	return (EXIT_SUCCESS);
}
