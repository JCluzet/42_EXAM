# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/21 02:04:11 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='epur_str.c'

bash .system/auto_correc_program.sh $FILE 
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE  "See? It's easy to print the same thing"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE " this        time it      will     be    more complex  . "
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE  "No S*** Sherlock..." "nAw S*** ShErLaWQ..."
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "comme c'est cocasse" "vous avez entendu, Mathilde ?"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi


bash .system/auto_correc_program.sh $FILE "5"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "Too" "Many" "Arguments"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "7"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

touch .system/verif/passed;
