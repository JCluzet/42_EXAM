#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	ascii[255] = {0};
		
		for (int i = 0; i < 3; i += 1)
		{
			int j = 0;
			while (argv[i][j])
			{
				if (ascii[(int)argv[i][j]] == 0)
				{
					ascii[(int)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j += 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
