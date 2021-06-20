#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char c;
    t_point p;

    c = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    if (begin.y > 0 && tab[begin.y - 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin.y - 1;
        flood_fill(tab, size, p);
    }
    if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin.y + 1;
        flood_fill(tab, size, p);
    }
    if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] == c)
    {
        p.x = begin.x + 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
    if (begin.x > 0 && tab[begin.y][begin.x - 1] == c)
    {
        p.x = begin.x - 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
}
/*
#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;

    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {0, 0};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
*/