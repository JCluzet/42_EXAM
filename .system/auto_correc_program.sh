# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_correc_program.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/21 13:28:19 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

source .system/git_logic.sh
source .system/file_logic.sh

FILE="../../rendu/$2/$1"

tmp=""
timeout=1

if [ -e .system/grading/traceback ];then
    rm .system/grading/traceback;
fi

cd .system/grading
pull_files
check_files $FILE
gcc -o source "$1"
./source "${@:3}" | cat -e > sourcexam       #TESTING
rm source
{
gcc -o final "$FILE"
}  2>.dev
{
./final "${@:3}" | cat -e > finalexam &       #TESTING
PID=$!
}  &>/dev/null


# loop 1 second for 20 sec
for i in {1..20}
do
    sleep 1
    # if PID is not running, then exit
    # if i is 5, 10, 15, 19 then echo "waiting..."
    if [ $i -eq 5 ] || [ $i -eq 10 ] || [ $i -eq 15 ] || [ $i -eq 19 ]; then
        echo "waiting..."
    fi
    if ! ps -p $PID > /dev/null
    then
        timeout=0
        break
    fi
done


DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ START TEST " >> traceback
        printf "        💻 TEST\n./a.out ${@:3}\n" >> traceback
        printf "        🔎 YOUR OUTPUT:\n" >> traceback
		git_print_error_if_needed
		files_print_error_if_needed $FILE
        cat finalexam >> traceback
        if [ $timeout -eq 1 ]
        then
        printf "   ❌ TIMEOUT\n" >> traceback
		elif [ -e final ]
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