
void    ft_putstr(char *str);
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("ft_putstr(\"\")\n");
        return(0);
    }
    printf("ft_putstr(\"%s\")\n", argv[1]);
    ft_putstr(argv[1]);
    printf("\n");
    return(0);
}