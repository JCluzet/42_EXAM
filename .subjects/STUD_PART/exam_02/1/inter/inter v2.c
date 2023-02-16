#include<unistd.h>

int main(int ac, char *argv[])
{
	int t[250] = {0};
	int i = 0;
	int j = 0;

	if(ac == 3)
	{
		while(argv[2][j])
		{
			t[argv[2][j]] = 1;
			j++;
		}
		while(argv[1][i])
		{
			if(t[argv[1][i]] == 1)
			{
				write(1, &argv[1][i] ,1);
				t[argv[1][i]] = 0;
			}
			i++;
		}
	}
	write(1,"\n",1);
	return 0;
}
