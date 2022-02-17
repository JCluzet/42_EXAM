# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/02/17 15:00:04 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='get_next_line.c'
MAIN='mainboc.c'
MAIN1='../.system/verif/mainstud.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .subject_save/12/get_next_line/test .

cd .system/verif
cp test ../../rendu/test
gcc -o boc $FILE -D BUFFER_SIZE=3 $MAIN
./boc < test | cat -e > sourcexam       #TESTING
rm boc
cd ../../rendu
{
gcc -Wall -Wextra -Werror -o stud $FILE -D BUFFER_SIZE=3 $MAIN1 # our
}  &>../.system/verif/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
mv studleak ../.system/verif/studleak
rm stud
}  &>/dev/null

cd ../.system/verif
{
cat studleak | tail -n 4 | tail -c 37 > leakstud
cat bocleak | tail -n 4 | tail -c 37 > leakboc
} &>/dev/null
DIFF=$(diff sourcexam finalexam)
DIFF1=$(diff leakstud leakboc)
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
if [ "$DIFF1" != "" ]
then
		index=$(($index + 1))
		{
		cat studleak >> traceback
		} &>/dev/null
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

{
rm studleak
rm bocleak
rm ../../../rendu/test
} &>/dev/null









cp test ../../rendu/test
gcc -o boc $FILE -D BUFFER_SIZE=1232 $MAIN
./boc < test | cat -e > sourcexam       #TESTING
rm boc
cd ../../rendu
{
gcc -Wall -Wextra -Werror -o stud $FILE -D BUFFER_SIZE=1232 $MAIN1 # our
}  &>../.system/verif/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
mv studleak ../.system/verif/studleak
rm stud
}  &>/dev/null

cd ../.system/verif
{
cat studleak | tail -n 4 | tail -c 37 > leakstud
cat bocleak | tail -n 4 | tail -c 37 > leakboc
} &>/dev/null
DIFF=$(diff sourcexam finalexam)
DIFF1=$(diff leakstud leakboc)
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
if [ "$DIFF1" != "" ]
then
		index=$(($index + 1))
		{
		cat studleak >> traceback
		} &>/dev/null
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

{
rm studleak
rm bocleak
rm ../../../rendu/test
} &>/dev/null
















cp test ../../rendu/test
gcc -Wall -Wextra -Werror -o boc $FILE -D BUFFER_SIZE=0 $MAIN
./boc < test | cat -e > sourcexam       #TESTING
rm boc
cd ../../rendu
{
gcc -Wall -Wextra -Werror -o stud $FILE -D BUFFER_SIZE=0 $MAIN1 # our
}  &>../.system/verif/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/verif/
mv studleak ../.system/verif/studleak
rm stud
}  &>/dev/null

cd ../.system/verif
{
cat studleak | tail -n 4 | tail -c 37 > leakstud
cat bocleak | tail -n 4 | tail -c 37 > leakboc
} &>/dev/null
DIFF=$(diff sourcexam finalexam)
DIFF1=$(diff leakstud leakboc)
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
if [ "$DIFF1" != "" ]
then
		index=$(($index + 1))
		{
		cat studleak >> traceback
		} &>/dev/null
		echo '\n' >> traceback
		echo "-------" >> traceback
fi

{
rm studleak
rm bocleak
rm ../../../rendu/test
} &>/dev/null

if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
#rm sourcexam
