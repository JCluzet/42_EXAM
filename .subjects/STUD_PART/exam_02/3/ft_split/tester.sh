# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:00:29 by pandalaf          #+#    #+#              #
#    Updated: 2022/11/06 22:29:59 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_split.c'
ASSIGN='ft_split'

bash .system/auto_correc_main.sh $FILE $ASSIGN "three words apart"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "  starting and ending   "
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
