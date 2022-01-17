# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/01/17 02:20:42 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='get_next_line.c'
MAIN='main.c'
MAIN1='../.system/verif/main.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .system/verif/test rendu/

cd .system/verif
gcc -Wall -Wextra -Werror  -o source $FILE -D BUFFER_SIZE=3 $MAIN
./source < test | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE -D BUFFER_SIZE=3 $MAIN1
}  &>../.system/verif/traceback
{
./final < test | cat -e > finalexam        #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi
rm finalexam

cd .system/verif
gcc -Wall -Wextra -Werror  -o source $FILE -D BUFFER_SIZE=1 $MAIN
./source < test | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE -D BUFFER_SIZE=1 $MAIN1
}  &>../.system/verif/traceback
{
./final < test | cat -e > finalexam        #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi
rm finalexam

cd .system/verif
gcc -Wall -Wextra -Werror  -o source $FILE -D BUFFER_SIZE=1000 $MAIN
./source < test | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE -D BUFFER_SIZE=1000 $MAIN1
}  &>../.system/verif/traceback
{
./final < test | cat -e > finalexam        #TESTING
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
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi
rm finalexam


gcc -Wall -Wextra -Werror  -o source $FILE -D BUFFER_SIZE=2 $MAIN
touch houne
./source < houne | cat -e > sourcexam    #TESTING
rm houne
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE -D BUFFER_SIZE=2 $MAIN1
touch houne
./final < houne | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm houne
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

gcc -Wall -Wextra -Werror  -o source $FILE -D BUFFER_SIZE=0 $MAIN
touch houne
./source < houne | cat -e > sourcexam    #TESTING
rm houne
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $FILE -D BUFFER_SIZE=0 $MAIN1
touch houne
./final < houne | cat -e > finalexam     #TESTING
mv finalexam ../.system/verif/
rm houne
rm final
}  &>/dev/null
cd ../.system/verif
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		cat sourcexam >> traceback
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

rm rendu/test

if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
