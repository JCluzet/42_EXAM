# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 09:41:03 by pandalaf          #+#    #+#              #
#    Updated: 2022/11/07 10:18:31 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='rev_wstr.c'
ASSIGN='rev_wstr'

bash .system/auto_correc_program.sh $FILE $ASSIGN "order in us put"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "  done! well it, did You  "
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
