# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/18 15:52:51 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='search_and_replace.c'

bash .system/auto_correc_program.sh $FILE 
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "Papache est un sabre" "a" "o"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "zaz" "art" "zul"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "zaz" "r" "u"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "jacob" "a" "b" "c" "e"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "ZoZ eT Dovid oiME le METol." "o" "a"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi


bash .system/auto_correc_program.sh $FILE "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "AkjhZ zLKIJz , 23y "
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

bash .system/auto_correc_program.sh $FILE "Alex."
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "abacadaba 42!"
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE ""
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

touch .system/verif/passed;
