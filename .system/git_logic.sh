# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    git_logic.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2022/12/15 17:01:20 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

pull_files()
{
	git pull origin master &>/dev/null
	if [ $? -ne 0 ]; then
		GIT_NO_PUSH_ERR=1
	fi
}

git_print_error_if_needed()
{
	if [ $GIT_NO_PUSH_ERR -eq 1 ] ; then
		printf "GIT ERROR:\nwe pulled but there was nothing there...\n" >> traceback
	fi
	GIT_NO_PUSH_ERR=0
}
