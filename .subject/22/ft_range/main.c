#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end);

int main(int argc, char **argv)
{
	int	*lst;
	int	*head;

	lst = ft_range(atoi(argv[1]), atoi(argv[2]));
	head = lst;
	while (*lst)
	{
		printf("%i\n", *lst);
		lst++;	
	}
	free(head);
	return (0);
}
