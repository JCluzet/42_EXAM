# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfregni <tfregni@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2023/11/05 01:00:46 by tfregni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN='main.cpp'
MAIN1='cpp_module00/main.cpp'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
clang++ -Wall -Wextra -Werror -std=c++98 -o source $MAIN Warlock.cpp
./source | cat -e > sourcexam       #TESTING
rm source
cp main.cpp ../../rendu/cpp_module00
cd ../../rendu
{
clang++ -Wall -Wextra -Werror -std=c++98 -o final $MAIN1 cpp_module00/Warlock.cpp
}  &>../.system/grading/traceback
rm -f cpp_module00/main.cpp
# if there is a traceback file, exit this script
# if [ -e ../.system/grading/traceback ]
# then
# 	mv ../.system/grading/traceback ../traceback
# 	exit 1
# fi
{
./final | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
rm final
}  &>/dev/null
cd ../.system/grading
DIFF=$(diff sourcexam finalexam)
# echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		echo "<-------------- OUR OUTPUT ------------>" >> traceback
		cat finalexam >> traceback
		# echo '\n' >> traceback
		if [ "$(cat finalexam)" != "" ]
		then
		echo "<-------------- MUST BE : ------------>" >> traceback
		cat sourcexam >> traceback
		echo "<--------------    DIFF :   ------------>" >> traceback
		# echo "DIFF : " >> traceback
		echo "$DIFF" >> traceback
		else
		echo "Compilation Error stop." >> traceback
		printf "\nLittle reminder: Here you must have a Warlock.cpp & Warlock.hpp files." >> traceback
		fi
		# echo '\n' >> traceback
fi
rm finalexam

if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
