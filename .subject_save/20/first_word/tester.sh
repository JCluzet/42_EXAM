# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/16 16:35:50 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='first_word.c'

bash .system/auto_correc_program.sh $FILE 
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "abc"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "FOR PONY"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "this        ...       is sparta, then again, maybe    not"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "   "
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "a" "b"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "  lorem,ipsum  "
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi
touch passed;
