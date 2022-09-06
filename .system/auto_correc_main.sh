# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_correc_main.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/01 23:31:55 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE="../../rendu/$2/$1"
MAIN='main.c'

tmp=""

if [ -e .system/grading/traceback ];then
    rm .system/grading/traceback;
fi

cd .system/grading
gcc -o source "$1" $MAIN
./source "${@:3}" | cat -e > sourcexam       #TESTING
rm source
{
gcc -o final "$FILE" $MAIN
}  2>.dev
{
./final "${@:3}" | cat -e > finalexam        #TESTING
}  &>/dev/null

DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ START TEST " >> traceback
        printf "        💻 TEST\n./a.out ${@:3}\n" >> traceback
        printf "        🔎 YOUR OUTPUT:\n" >> traceback
        cat finalexam >> traceback
		if [ -e final ]
		then
        printf "        🗝 EXPECTED OUTPUT:\n" >> traceback
		cat sourcexam >> traceback
		else
        printf "\n";
        echo "$(cat .dev)" >> traceback
        rm .dev
		printf "\n        ❌ COMPILATION ERROR\n" >> traceback
		fi
        echo "----------------8<------------- END TEST ]" >> traceback
fi
{
rm final
rm finalexam
rm sourcexam
} &>/dev/null
cd ../..