
char	*ft_strcpy(char *s1, char *s2);
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * 100);
    printf("ft_strcpy(\"%s\", str) = %s\n", argv[1], ft_strcpy(str, argv[1]));
    free(str);
    return(0);
}