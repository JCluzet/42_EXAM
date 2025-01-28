# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 13:06:02 by marcsilv          #+#    #+#              #
#    Updated: 2025/01/28 13:17:10 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='ft_strpbrk.c'                                                  # exercise filename
ASSIGN='ft_strpbrk'                                                  # folder name

bash .system/auto_correc_main.sh $FILE $ASSIGN                # This partition is a test, just add as much arguments you need (Here there is no arguments)
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN  "Hello, world" "aeiou"      # A test with 1 argument who is "225225"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "abcdef" "xyz"  # A test with 2 arguments which are "8333325" and "42"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

bash .system/auto_correc_main.sh $FILE $ASSIGN "abcdef" ""
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

bash .system/auto_correc_main.sh $FILE $ASSIGN "" "abcdef"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

bash .system/auto_correc_main.sh $FILE $ASSIGN "" ""
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

touch .system/grading/passed;     # This line must be at the end of your file
