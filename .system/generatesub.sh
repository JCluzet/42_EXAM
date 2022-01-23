#!bin/bash
	gen=$(ls .subject/$1 | wc -l)
	if [ $gen -eq 0 ]
	then
		echo "No subject found"
		exit 1
	fi
	nb=$(($RANDOM % $gen))
	if [ $nb -eq 0 ]
	then
		nb=1
	fi
	fichier=$(ls .subject/$1 | sed -n "$nb"p)
	{
	cd .system/
	mkdir verif
	cd ..
	} &>/dev/null
	cp -r .subject/$1/$fichier/subject.en.txt subject.en.txt
	cp -r .subject/$1/$fichier/subject.fr.txt subject.fr.txt > /dev/null
	cp -r .subject/$1/$fichier/* .system/verif/
	printf ${fichier:4} > .system/verif/nameofex
	# chmod 777 .system/verif/nameofex.txt
	{
	rm -r traceback
	}	&>/dev/null
	rm -r .subject/$1/$fichier

# Shuffle to randomize the project, then copie subject/exercice.c and the tester.sh
