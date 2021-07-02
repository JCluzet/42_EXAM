# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 01:05:24 by jcluzet           #+#    #+#              #
#    Updated: 2021/07/02 04:12:37 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make reset
	@gcc .system/main.c .system/push.c .system/generate_subject.c .system/GNL/get_next_line.c .system/GNL/get_next_line_utils.c && ./a.out

exam:
	@make reset
	@gcc .system/main.c .system/push.c .system/generate_subject.c .system/GNL/get_next_line.c .system/GNL/get_next_line_utils.c && ./a.out

help:
	@echo "\x1B[37mType \x1B[32m> /make exam \x1B[37mto start the exam"
	@echo "\x1B[37mType \x1B[32m> /make reset \x1B[37mto reset 42_EXAM"

clean:
	@echo "\033[33m      Type > /make help for some help"

reset:
	@rm -rf .subject
	@cp -r .subject_save .subject
	@rm -rf .system/verif/*
	@rm -rf rendu/
	@rm -rf subject.en.txt
	@rm -rf traceback

fclean:
	@echo "\033[33m      Type > /make help for some help"

re:
	@echo "\033[33m      Type > /make help for some help"
