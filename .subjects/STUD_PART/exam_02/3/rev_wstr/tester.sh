# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 09:41:03 by pandalaf          #+#    #+#              #
#    Updated: 2022/12/14 17:52:08 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='rev_wstr.c'
ASSIGN='rev_wstr'

bash .system/auto_correc_program.sh $FILE $ASSIGN "order in us put"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "done! well it, did You"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "You hate people! But I love gatherings. Isn't it ironic?"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "abcdefghijklm"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
