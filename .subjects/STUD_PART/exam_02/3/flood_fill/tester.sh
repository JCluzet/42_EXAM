# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 23:07:59 by pandalaf          #+#    #+#              #
#    Updated: 2022/11/07 00:37:40 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='flood_fill.c'
ASSIGN='flood_fill'

bash .system/auto_correc_main.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
