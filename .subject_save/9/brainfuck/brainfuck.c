/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:05:56 by exam              #+#    #+#             */
/*   Updated: 2019/03/14 14:02:53 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		go_to_matching(char *operations, int curr)
{
	int balance = 0;

	if (operations[curr] == '[')
	{
		curr++;
		while (!(operations[curr] == ']' && balance == 0))
		{
			if (operations[curr] == '[')
				balance++;
			else if (operations[curr] == ']')
				balance--;
			curr++;
		}
		// we are right over a ] so, before advancing, we should retrocede one
		curr--;
	}
	else if (operations[curr] == ']')
	{
		curr--;
		while (!(operations[curr] == '[' && balance == 0))
		{
			if (operations[curr] == ']')
				balance++;
			else if (operations[curr] == '[')
				balance--;
			curr--;
		}
		// we are right over a [ so, before advancing, we should retrocede one
		curr--;
	}
	return (curr);
}

void	fuck_brain(char *operations)
{
	int curr = 0;
	int pointer = 0;
	char bytes[2048];

	while (curr < 2048)
		bytes[curr++] = 0;

	curr = 0;
	while (operations[curr])
	{
		if (operations[curr] == '>')
			pointer++;
		else if (operations[curr] == '<')
			pointer--;
		else if (operations[curr] == '+')
			bytes[pointer]++;
		else if (operations[curr] == '-')
			bytes[pointer]--;
		else if (operations[curr] == '.')
			write(1, &bytes[pointer], 1);
		else if (operations[curr] == '[')
		{
			if (bytes[pointer] == 0)
				curr = go_to_matching(operations, curr);
		}
		else if (operations[curr] == ']')
		{
			if (bytes[pointer] != 0)
				curr = go_to_matching(operations, curr);
		}
		curr++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fuck_brain(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
