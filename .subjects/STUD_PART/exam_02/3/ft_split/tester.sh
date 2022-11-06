# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:00:29 by pandalaf          #+#    #+#              #
#    Updated: 2022/11/06 16:05:38 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_split.c'
ASSIGN='ft_split'

bash .system/auto_correc_main.sh $FILE $ASSIGN "three words apart"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
