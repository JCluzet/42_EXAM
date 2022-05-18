# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/18 15:35:27 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_strcpy.c'

bash .system/auto_correc_main.sh $FILE "Ceci permet de decouvrir le fonctionnement de ton ft_strcpy."
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE "OH ! Tu devrais avoir reussi ce test."
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

touch .system/verif/passed;
