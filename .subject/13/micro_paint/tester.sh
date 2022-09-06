# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/01/15 23:54:04 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='micro_paint.c'


index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .system/verif/0 rendu/0
cp .system/verif/1 rendu/1
cp .system/verif/2 rendu/2
cp .system/verif/3 rendu/
cp .system/verif/4 rendu/
cp .system/verif/5 rendu/
cp .system/verif/6 rendu/
cp .system/verif/7 rendu/
cp .system/verif/8 rendu/

cd .system/verif
gcc -Wall -Wextra -Werror  -o source $FILE
./source 0 | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
}  &>../.system/verif/traceback
{
./final 0 | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
rm final
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



gcc -Wall -Wextra -Werror  -o source $FILE
./source 1 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 1 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 2 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 2 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 3 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 3 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 4 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 4 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 5 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 5 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 6 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 6 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 7 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 7 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 8 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 8 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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
./source 32 | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE
./final 32 | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm final
}  &>/dev/null
cd ../.system/verif
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

cd ../../


rm rendu/0
rm rendu/1
rm rendu/2
rm rendu/3
rm rendu/4
rm rendu/5
rm rendu/6
rm rendu/7
rm rendu/8

cd .system/verif





if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
