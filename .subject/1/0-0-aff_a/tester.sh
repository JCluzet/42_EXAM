# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2021/06/20 19:05:17 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='aff_a.c'


index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/verif
gcc -o source $FILE
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE
}  &>../.system/verif/traceback
{
./final | cat -e > finalexam        #TESTING
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



gcc -o source $FILE
./source abc | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE
./final abc | cat -e > finalexam     #TESTING
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



gcc -o source $FILE
./source "dubO a POIL" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE
./final "dubO a POIL" | cat -e > finalexam     #TESTING
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




gcc -o source $FILE
./source "zz sent le poney" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE
./final "zz sent le poney" | cat -e > finalexam     #TESTING
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




gcc -o source $FILE
./source "AAAAaaaaaaaaAa" | cat -e > sourcexam    #TESTING
rm source
cd ../../rendu
{
gcc -o final $FILE
./final "AAAAaaaaaaaaAa" | cat -e > finalexam     #TESTING
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











if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
