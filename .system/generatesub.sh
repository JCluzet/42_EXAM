#!bin/bash
	nb=$(jot -r 1 1 "$(ls .subject/$1 | wc -l)")
	fichier=$(ls .subject/$1 | sed -n "$nb"p)

	{
	cd .system/
	mkdir verif
	cd ..
	} &>/dev/null
	cp -r .subject/$1/$fichier/subject.en.txt subject.en.txt
	cp -r .subject/$1/$fichier/subject.fr.txt subject.fr.txt
	cp -r .subject/$1/$fichier/* .system/verif/
	printf ${fichier:4} > .system/verif/nameofex
	# chmod 777 .system/verif/nameofex.txt
	{
	rm -r traceback
	}	&>/dev/null
	rm -r .subject/$1/$fichier

# Shuffle to randomize the project, then copie subject/exercice.c and the tester.sh
