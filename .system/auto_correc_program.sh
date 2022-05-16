# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_correc_program.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/16 17:30:45 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE="../../rendu/$1"

tmp=""

if [ -e .system/verif/traceback ];then
    rm .system/verif/traceback;
fi

cd .system/verif
gcc -o source "$1"
./source "${@:2}" | cat -e > sourcexam       #TESTING
rm source
{
gcc -o final "$FILE"
}  2>.dev
{
./final "${@:2}" | cat -e > finalexam        #TESTING
}  &>/dev/null
DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ START TEST " >> traceback
        printf "        💻 TEST\n./a.out ${@:2}\n" >> traceback
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