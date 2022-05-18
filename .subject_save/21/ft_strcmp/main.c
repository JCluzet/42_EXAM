
int    ft_strcmp(char *s1, char *s2);
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 3)
        printf("ft_strcmp(\"%s\", \"%s\") = %d\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
    return(0);
}