/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:17:55 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/06 23:19:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

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

int	main(void)
{
	t_point size = {8, 5};
	char *zone1[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};
	char *zone2[] = {
		"11111111",
		"10011001",
		"10100101",
		"11000011",
		"11111111",
	};

	// Make area arrays
	char**  area1 = make_area(zone1, size);
	char**  area2 = make_area(zone1, size);
	char**  area3 = make_area(zone2, size);
	// Present map 1
	printf("Map 1\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	// Assign starting points
	t_point begin1 = {7, 4};
	t_point begin2 = {3, 1};
	t_point begin3 = {0, 0};
	// Perform first two operations
	flood_fill(area1, size, begin1);
	flood_fill(area2, size, begin2);
	printf("Start (7, 4)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	printf("Start (3, 1)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area2[i]);
	printf("\n-----------\n");
	// Present map 2
	printf("Map 2\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	printf("\n");
	// Perform third operation
	flood_fill(area3, size, begin3);
	printf("Start (0, 0)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	return (0);
}
