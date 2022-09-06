# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/18 18:29:57 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_strcmp.c'

bash .system/auto_correc_main.sh $FILE "hello World" "hello world"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE "hello World" ""
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE "13268!" "+13268!"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

touch .system/verif/passed;
