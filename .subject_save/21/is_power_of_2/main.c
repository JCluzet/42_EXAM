
int	    is_power_of_2(unsigned int n);
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc == 1)
        return(0);
    printf("is_power_of_2(\"%s\") = %d\n", argv[1], is_power_of_2(atoi(argv[1])));
    return(0);
}