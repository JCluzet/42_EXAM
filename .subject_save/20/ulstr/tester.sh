# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/18 15:54:22 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ulstr.c'

bash .system/auto_correc_program.sh $FILE 
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification."
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "
if [ -e .system/verif/traceback ];then
    mv .system/verif/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot"
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
