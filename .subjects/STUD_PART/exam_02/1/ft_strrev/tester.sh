FILE='ft_strrev.c'                                                  # exercice filename
ASSIGN='ft_strrev'                                                  # folder name

bash .system/auto_correc_main.sh 
$FILE $ASSIGN  "hello"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh 
$FILE $ASSIGN  "same same same"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
