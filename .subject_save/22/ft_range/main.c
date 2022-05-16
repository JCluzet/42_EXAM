#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end);

int main()
{
	int	*lst;
	int	*head;

	lst = ft_range(3, 16);
	head = lst;
	while (*lst)
	{
		printf("%i\n", *lst);
		lst++;	
	}
	free(head);
	return (0);
}
