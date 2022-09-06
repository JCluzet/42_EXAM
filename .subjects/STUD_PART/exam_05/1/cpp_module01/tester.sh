# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/09/01 23:52:05 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN='main.cpp'
MAIN1='../.system/grading/main.cpp'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
clang++ -Wall -Wextra -Werror -std=c++98 -o source Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp $MAIN
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
clang++ -Wall -Wextra -Werror -std=c++98 -o final cpp_module01/Warlock.cpp cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Dummy.cpp cpp_module01/Fwoosh.cpp $MAIN1
}  &>../.system/grading/traceback
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
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat sourcexam >> traceback
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		echo "<--------------~-~-~-~-~-~-~-~-~------------>\n\n" >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
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
