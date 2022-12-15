# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    file_logic.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/12/15 17:10:51 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

check_files()
{
	local FILE="$1"

	if [ $GIT_NO_PUSH_ERR -eq 1 ] ; then
		return 
	fi
	if [ ! -e "$FILE" ]; then
		NO_FILE_ERR=1
	fi
}

files_print_error_if_needed()
{
	local FILE="$1"

	if [ $NO_FILE_ERR -eq 1 ] ; then
		printf "FILE ERROR:\nfile '%s' does not exist make sure you pushed!\n" $FILE >> traceback
	fi
	NO_FILE_ERR=0
}