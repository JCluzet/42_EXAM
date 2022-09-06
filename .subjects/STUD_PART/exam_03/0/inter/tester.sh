# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/03 17:43:41 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='inter.c'
ASSIGN='inter/inter.c'


index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
gcc -Wall -Wextra -Werror  -o source $FILE
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
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
		echo "-------" >> traceback
fi
rm finalexam



gcc -Wall -Wextra -Werror  -o source $FILE
./source zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
./final zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e > finalexam     #TESTING
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
		echo "-------" >> traceback
fi
rm finalexam



gcc -Wall -Wextra -Werror  -o source $FILE
./source ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
./final ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e > finalexam     #TESTING
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
		echo "-------" >> traceback
fi
rm finalexam




gcc -Wall -Wextra -Werror  -o source $FILE
./source "rien" "cette phrase ne cache rien" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
./final "rien" "cette phrase ne cache rien" | cat -e > finalexam     #TESTING
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
		echo "-------" >> traceback
fi
rm finalexam




gcc -Wall -Wextra -Werror  -o source $FILE
./source "rien" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
./final "rien" | cat -e > finalexam     #TESTING
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
		echo "-------" >> traceback
fi
rm finalexam

gcc -Wall -Wextra -Werror  -o source $FILE
./source "AAAAaaaaaaaaAa" "test" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN
./final "AAAAaaaaaaaaAa" "test" | cat -e > finalexam     #TESTING
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
		echo "-------" >> traceback
fi

{
mv traceback ../../traceback
}	&>/dev/null

rm finalexam
{
rm sourcexam
rm a.out
rm .dev
} &>/dev/null
# rm test.sh

# cd ../.system/grading

#mv .system/tester.sh .system/grading/tester.sh


if [ $index -eq 0 ]
then
	# echo "OK"
	touch passed
fi