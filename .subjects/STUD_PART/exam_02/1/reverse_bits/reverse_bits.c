/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:15:19 by tsargsya          #+#    #+#             */
/*   Updated: 2025/01/24 12:15:19 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char res = 0;
	int i = 0;
	while (i < 8)
	{
		res = res << 1;
		res = res | (octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (res);
}
