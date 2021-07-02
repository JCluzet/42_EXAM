# include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet);

int		main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	print_bits(n);
	write(1, "\n", 1);
}
