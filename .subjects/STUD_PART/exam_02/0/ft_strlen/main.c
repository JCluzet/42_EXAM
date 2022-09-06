
int     ft_strlen(char *str);
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("ft_strlen(\"\") = %d\n", ft_strlen(""));
        return(0);
    }
    printf("ft_strlen(\"%s\") = %d\n", argv[1], ft_strlen(argv[1]));
    return(0);
}