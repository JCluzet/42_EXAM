# flood_fill

## Conceptual Overview
### The Problem
We are asked to write a function that takes arguments of a 2-dimensional array of chars and two coordinate pairs representing the dimensions of the array and the starting point in the array, respectively. The function replaces the starting character and all "connected" characters with 'F', where connected characters are those that have the same value as the starting character and are one space above, below, to the left, or to the right of the starting character or another connected character.

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : flood_fill
	Expected files   : *.c, *.h
	Allowed functions: -
	--------------------------------------------------------------------------------

	Write a function that takes a char ** as a 2-dimensional array of char, a 
	t_point as the dimensions of this array and a t_point as the starting point.

	Starting from the given 'begin' t_point, this function fills an entire zone 
	by replacing characters inside with the character 'F'. A zone is an group of 
	the same character delimitated horizontally and vertically by other characters
	or the array boundry.

	The flood_fill function won't fill diagonally.

	The flood_fill function will be prototyped like this:
	  void  flood_fill(char **tab, t_point size, t_point begin);

	The t_point structure is prototyped like this:

	  typedef struct  s_point
	  {
	    int           x;
	    int           y;
	  }               t_point;

	Example:

	$> cat test.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "flood_fill.h"

	char** make_area(char** zone, t_point size)
	{
		char** new;

		new = malloc(sizeof(char*) * size.y);
		for (int i = 0; i < size.y; ++i)
		{
			new[i] = malloc(size.x + 1);
			for (int j = 0; j < size.x; ++j)
				new[i][j] = zone[i][j];
			new[i][size.x] = '\0';
		}

		return new;
	}

	int main(void)
	{
		t_point size = {8, 5};
		char *zone[] = {
			"11111111",
			"10001001",
			"10010001",
			"10110001",
			"11100001",
		};

		char**  area = make_area(zone, size);
		for (int i = 0; i < size.y; ++i)
			printf("%s\n", area[i]);
		printf("\n");

		t_point begin = {7, 4};
		flood_fill(area, size, begin);
		for (int i = 0; i < size.y; ++i)
			printf("%s\n", area[i]);
		return (0);
	}

	$> gcc flood_fill.c test.c -o test; ./test
	11111111
	10001001
	10010001
	10110001
	11100001

	FFFFFFFF
	F000F00F
	F00F000F
	F0FF000F
	FFF0000F
	$> 
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [flood_fill.c](flood_fill.c)

### Approach

Save the value of the character at the starting location. For each location beginning with the starting position, check if the current location is in-bounds and if the character at the current location matches the character originally at the starting location. If so, change the character at the current location to 'F' and repeat with the locations one row above, one row below, one column to the left, and one column to the right.

### Code
```C
// This code is heavily influenced by @jochang's solution: github.com/MagicHatJo

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
```