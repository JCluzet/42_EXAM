/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:43:40 by mbarutel          #+#    #+#             */
/*   Updated: 2022/01/17 17:48:08 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi_base(const char *str, int str_base)
{
    int     ret;
    int     sign;
    char    *char_input;
    
    ret = 0;
    sign = 1;
    char_input = "0123456789abcdef";
    if (str[0] == '-' || str[0] == '+')
    {
        if (str[0] == '-')
            sign = -1;
        str++;
    }
    while (str[0] != '\0')
    
}