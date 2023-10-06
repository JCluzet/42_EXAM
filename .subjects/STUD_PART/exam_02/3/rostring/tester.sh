# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 00:45:37 by pandalaf          #+#    #+#              #
#    Updated: 2023/10/06 10:27:47 by jkulka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='rostring.c'
ASSIGN='rostring'

bash .system/auto_correc_program.sh $FILE $ASSIGN "abc   "
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "Que la      lumiere soit et la lumiere fut"
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "     AkjhZ zLKIJz , 23y"
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "first" "2" "11000000"
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "This is a test "
if [ -e .system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
