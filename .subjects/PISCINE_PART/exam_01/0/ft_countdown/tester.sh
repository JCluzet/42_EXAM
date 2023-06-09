# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/01 23:57:48 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_countdown.c'
ASSIGN='ft_countdown/ft_countdown.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
gcc -o source $FILE
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -o final $ASSIGN
}  &>../.system/grading/traceback
{
./final | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
rm final
}  &>/dev/null
cd ../.system/grading
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
		echo "\n-------" >> traceback
fi
rm finalexam



gcc -o source $FILE
./source abc | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $ASSIGN
./final abc | cat -e > finalexam     #TESTING
mv finalexam ../.system/grading/
rm final
}  &>/dev/null
cd ../.system/grading
DIFF=$(diff sourcexam finalexam)
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
		echo "\n-------" >> traceback
fi



if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
