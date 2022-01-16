# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/01/16 18:11:16 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='microshell.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .system/verif/test.sh rendu/

cd .system/verif
gcc -Wall -Wextra -Werror $FILE
cp a.out ../../rendu/a.out
cd ../../rendu
sh test.sh | cat -e > sourcexam       #TESTING
rm a.out
{
gcc -Wall -Wextra -Werror $FILE
}  &>../.system/verif/traceback
{
sh test.sh | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
rm a.out
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo "-------" >> traceback
fi
rm finalexam

cd ../../

rm rendu/test.sh

cd .system/verif

mv .system/tester.sh .system/verif/tester.sh


if [ $index -eq 0 ]
then
	echo "OK"
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
