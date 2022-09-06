/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:35:46 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/06 17:14:14 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int	check_input(char *s)
{
	int	num_c;
	int	op_c;

	num_c = 0;
	op_c = 0;
	while (*s)
	{
		if (!(is_op(*s) || is_digit(*s) || is_space(*s)))
			return (0);
		if (is_op(*s))
		{
			if (num_c && (*(s - 1)) && !is_space(*(s - 1)))
					return (0);
			op_c++;
			if ((*s == '-' || *s == '+') && (*(s + 1)) &&
					is_digit(*(s + 1)))
				op_c--;
		}
		else if (is_digit(*s))
		{
			if (!num_c || (*(s - 1) && !is_digit(*(s - 1))))
				num_c++;
		}
		if (is_space(*s) && num_c <= op_c)
			return (0);
		++s;
	}
	return (num_c - op_c == 1 ? 1 : 0);
}
