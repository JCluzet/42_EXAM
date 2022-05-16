#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				if (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t')
					write(1, "   ", 3);
				i++;
			}
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
		}
	}
	return (0);
}
