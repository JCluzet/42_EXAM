
#include <stdio.h>
size_t	ft_strcspn(const char *s, const char *reject);

int main(int argc, char **argv)
{
    if (argc == 3)
        printf("ft_strcspn(\"%s\", \"%s\") = %zu\n", argv[1], argv[2], ft_strcspn(argv[1], argv[2]));
    return(0);
}