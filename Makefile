# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 01:05:24 by jcluzet           #+#    #+#              #
#    Updated: 2021/06/20 17:54:58 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "\033[33m      Tapez > /make help pour obtenir de l'aide"

exam:
	@make reset
	@gcc .system/main.c .system/push.c .system/generate_subject.c .system/GNL/get_next_line.c .system/GNL/get_next_line_utils.c && ./a.out


# \x1B[37m WHITE

# \x1B[32m GREEN
time:
	@gcc .system/main.c && ./a.out 0

help:
	@echo "\x1B[37mTapez \x1B[32m> /make exam \x1B[37mpour commencer l'exam"
	@echo "\x1B[37mTapez \x1B[32m> /make reset \x1B[37mpour reinitialiser l'exam"

clean:
	@echo "\033[33m      Tapez > /make help pour obtenir de l'aide"

reset:
	@rm -rf .subject
	@cp -r .subject_save .subject
	@rm -rf .system/verif/*
	@rm -rf rendu/
	@rm -rf subject.en.txt
	@rm -rf traceback

fclean:
	@echo "\033[33m      Tapez > /make help pour obtenir de l'aide"

re:
	@echo "\033[33m      Tapez > /make help pour obtenir de l'aide"
