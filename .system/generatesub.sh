	fichier=$(ls .subject/$1 | shuf -n1)

	cp -r .subject/$1/$fichier/subject.en.txt subject.en.txt
	cp -r .subject/$1/$fichier/*.c .system/verif/
	cp -r .subject/$1/$fichier/tester.sh .system/verif/
	{
	rm -r traceback
	}	&>/dev/null
	rm -r .subject/$1/$fichier
