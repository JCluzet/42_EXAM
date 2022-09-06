/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:27:13 by fwuensch          #+#    #+#             */
/*   Updated: 2019/03/25 15:14:43 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// YOU SHOULD NOT PUSH THIS FILE

#ifndef LIST_H
# define LIST_H

typedef struct     s_list
{
    int            data;
    struct s_list  *next;
}                  t_list;

#endif
