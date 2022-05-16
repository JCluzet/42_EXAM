# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_correc_main.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/05/16 17:23:55 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE="../../rendu/$1"
MAIN='main.c'

tmp=""

if [ -e .system/verif/traceback ];then
    rm .system/verif/traceback;
fi

cd .system/verif
gcc -o source "$1" $MAIN
./source "${@:2}" | cat -e > sourcexam       #TESTING
rm source
{
gcc -o final "$FILE" $MAIN
}  2>.dev
{
./final "${@:2}" | cat -e > finalexam        #TESTING
}  &>/dev/null

DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ ./a.out "$2" "$3" "$4" "$5" "$6" "$7" "$8" "$9" " >> traceback
        # echo "        💻 TEST ➪ ./a.out $2 $3 $4 $5 $6 $7 $8 $9" >> traceback
        printf "        🔎 YOUR OUTPUT:\n" >> traceback
        cat finalexam >> traceback
        printf "\n" >> traceback
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