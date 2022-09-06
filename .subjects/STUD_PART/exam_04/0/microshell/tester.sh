# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/03 22:53:09 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='microshell.c'
ASSIGN='microshell/microshell.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .system/grading/test.sh rendu/

cd .system/grading
{
	gcc -Wall -Wextra -Werror $FILE
} &>/dev/null
{
cp a.out ../../rendu/a.out
} &>/dev/null

cd ../../rendu
touch sourcexam
touch finalexam
sh test.sh &> sourcexam       #TESTING VRAI
{
rm a.out
} &>/dev/null
{
gcc -Wall -Wextra -Werror $ASSIGN
}  &>.dev
sh test.sh &> finalexam        #TESTING STUD
# {
# }  &>/dev/null



DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ START TEST " >> traceback
		if [ -e a.out ]
		then
        printf "        💻 ALL TESTS: \n\n$(cat ../.system/grading/test.sh)\n" >> traceback
        printf "\n\n        🔎 YOUR OUTPUT:\n" >> traceback
        cat finalexam >> traceback
        printf "\n\n        🗝 EXPECTED OUTPUT:\n" >> traceback
		cat sourcexam >> traceback
		else
		printf "        🔎 YOUR OUTPUT:\n" >> traceback
        # cat finalexam >> traceback
        printf "\n";
        echo "$(cat .dev)" >> traceback
        rm .dev
		printf "\n        ❌ COMPILATION ERROR\n" >> traceback
		fi
        echo "----------------8<------------- END TEST ]" >> traceback
		index=$((index+1))
fi
# exit
{
mv traceback ../traceback
}	&>/dev/null

rm finalexam
{
rm sourcexam
rm a.out
rm .dev
} &>/dev/null
rm test.sh

cd ../.system/grading

#mv .system/tester.sh .system/grading/tester.sh


if [ $index -eq 0 ]
then
	echo "OK"
	touch passed
fi
