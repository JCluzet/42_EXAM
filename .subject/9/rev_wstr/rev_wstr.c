/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:07:32 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 12:01:44 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		str_length(char *str)
{
	int	len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int		iswhitespace(char chr)
{
	return (chr == ' ' || chr == '\t');
}

void	print_reverse(char *str)
{
	// let's use three pointers to traverse the string backwards
	// the fast pointer will, dah, move faster then the others
	// mainly:
	int fast;	// will be placed at the start of a word
	int slow;	// will be placed at the end of a word
	int curr;	// will traverse the current word so we can write to stdout

	// shall we start at the end of the string
	fast = str_length(str) - 1;
	slow = fast;
	curr = fast;

	// until we reach the beginning of the string
	while (fast >= 0)
	{
		// here, fast should be at the last char of a word
		// so we place every pointer in the same place
		slow = fast;
		curr = fast;
		// now we place fast at the first char of the current word
		while (fast >= 0 && !iswhitespace(str[fast]))
			fast--;
		fast++;
		// we'll place curr where fast is, so we can write the curr word
		curr = fast;
		while (curr <= slow)
		{
			write(1, &str[curr], 1);
			curr++;
		}
		// now that we wrote the word, we add a whitespace
		// except that we should not add a whitespace for the last word
		if (fast > 0)
			write(1, " ", 1);
		// and we interrupt the loop if fast is at the first char
		// if it is not, so we move it two steps back
		fast--;
		fast--;
		// now we should be at the last char of previous word
		// so we can just repeat the process
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_reverse(av[1]);
	write(1, "\n", 1);
	return (1);
}
