# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/18 15:44:22 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_putstr.c'

bash .system/auto_correc_main.sh $FILE
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

touch .system/verif/passed;
