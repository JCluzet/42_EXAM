#!bin/bash
userpost="user=$LOGNAME"
date=$(date '+%F_%H:%M:%S')
time="time=$date"
	gen=$(ls .subject/$1 | wc -l)
	if [ $gen -eq 0 ]
	then
		echo "No subject found"
		exit 1
	fi
	nb=$(($RANDOM % $gen))
	# printf ">>>$nb"
	nb=$(($nb+1))

	fichier=$(ls .subject/$1 | sed -n "$nb"p)
	{
	cd .system/
	mkdir verif
	cd ..
	} &>/dev/null
	cp -r .subject/$1/$fichier/subject.en.txt subject.en.txt
	{
		cp -r .subject/$1/$fichier/subject.fr.txt subject.fr.txt
	} &>/dev/null
	cp -r .subject/$1/$fichier/* .system/verif/
	{
		cp -r .subject/$1/$fichier/our_micro_paint our_micro_paint
		cp -r .subject/$1/$fichier/our_mini_paint our_mini_paint
	}	&>/dev/null
	printf ${fichier:4} > .system/verif/nameofex
	# chmod 777 .system/verif/nameofex.txt
	{
	rm -r traceback
	}	&>/dev/null
	rm -r .subject/$1/$fichier
{
exo=$(ls .system/verif/*.c)
} &>/dev/null
usingpost="using=starting_$exo"
curl -X POST -F $userpost -F $usingpost -F $time https://user.grademe.fr/index.php > /dev/null 2>&1

# Shuffle to randomize the project, then copie subject/exercice.c and the tester.sh
