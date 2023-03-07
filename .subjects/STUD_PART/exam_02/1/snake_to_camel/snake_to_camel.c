#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i += 1)
		{
			if (argv[1][i] == '_')
			{
				i += 1;
				argv[1][i] -= 32;
			}
			write(STDOUT_FILENO, &argv[1][i], 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return EXIT_SUCCESS;
}
