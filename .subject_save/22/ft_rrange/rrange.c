/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrange.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:37:27 by mbarutel          #+#    #+#             */
/*   Updated: 2022/01/18 14:46:04 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     *ft_rrange(int start, int end)
{
    int *ret;

    ret = (int *)malloc((end - start));
    if (ret)
    {
        while (end >= start)
        {
            ret[end] = end;
            end--;
        }
        return (ret);   
    }
    return (NULL);
}