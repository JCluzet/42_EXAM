#include <stdio.h>
#include <stdlib.h>

int		is_power_of_2(unsigned int n);

int main(int argc, char **argv)
{
	printf("%d", is_power_of_2(atoi(argv[1])));
	return(0);
}
