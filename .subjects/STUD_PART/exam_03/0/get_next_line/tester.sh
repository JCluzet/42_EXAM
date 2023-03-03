# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2023/03/03 21:14:20 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='get_next_line.c'
ASSIGN='get_next_line/get_next_line.c'
MAIN='mainboc.c'
MAIN1='../.system/grading/mainstud.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cp .subjects/STUD_PART/exam_03/0/get_next_line/test .

cd .system/grading
cp test ../../rendu/test
gcc -o boc $FILE -D BUFFER_SIZE=3 $MAIN
./boc < test | cat -e > sourcexam       #TESTING
rm boc
cd ../../rendu
{
gcc -Wall -Wextra -Werror -o stud $ASSIGN -D BUFFER_SIZE=3 $MAIN1 # our
}  &>../.system/grading/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
mv studleak ../.system/grading/studleak
rm stud
}  &>/dev/null

cd ../.system/grading
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
gcc -Wall -Wextra -Werror -o stud $ASSIGN -D BUFFER_SIZE=1232 $MAIN1 # our
}  &>../.system/grading/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
mv studleak ../.system/grading/studleak
rm stud
}  &>/dev/null

cd ../.system/grading
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
gcc -Wall -Wextra -Werror -o stud $ASSIGN -D BUFFER_SIZE=0 $MAIN1 # our
}  &>../.system/grading/traceback
{
./stud < test | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
mv studleak ../.system/grading/studleak
rm stud
}  &>/dev/null

cd ../.system/grading
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
# if the file "traceback" is empty, delete it
if [ ! -s traceback ]
then
echo "Traceback of get_next_line seems to be broken, find your error by yourself <3" >> traceback
fi
mv traceback ../../traceback
}	&>/dev/null
#rm sourcexam
