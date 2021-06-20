/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:14:26 by exam              #+#    #+#             */
/*   Updated: 2018/04/16 16:51:15 by gmelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 1;
	int  t[32] = {0}; 
	int j ;

	if(ac == 1)
	{
		write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
		return 0;
	}
	i = 1;
	while (i < ac)
	{
		j = 1;
		if(av[i][0] == '-')
		{
			while(av[i][j] && av[i][j] >= 'a'  && av[i][j] <= 'z')
			{
				if(av[i][j] == 'h')
				{
					write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
					return 0;
				}

				t['z' - av[i][j] + 6] = 1;
				j++;
			}

			if (av[i][j])
			{
				write(1,"Invalid Option\n",15);
				return 0;
			}
			j++;
		}
		i++;
	}
	i = 0;
		while (i < 32)
		{
		t[i] = '0' + t[i];
		write(1,&t[i++],1);
			if(i == 32)
				write(1,"\n",1);
			else if(i % 8 == 0)
				write(1," ",1);

		}

	return 0;
}
