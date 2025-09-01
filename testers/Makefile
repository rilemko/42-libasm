# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:43:39 by mconreau          #+#    #+#              #
#    Updated: 2025/09/01 22:42:59 by mconreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#///// PROJECT : CONFIGURATION ////////////////////////////////////////////////#

# > GENERAL <<<<<<<<<<<<<<

NAME					:=	tester

#///// PROJECT : SOURCES //////////////////////////////////////////////////////#

SOURCES_MDT				:=	$(addprefix ./sources/,	main.c						\
							) \
							$(addprefix ./sources/tests/,	test_strlen.c		\
															test_strcpy.c		\
															test_strcmp.c		\
															test_write.c		\
															test_read.c			\
															test_strdup.c		\
							)

SOURCES_BNS				:=	$(addprefix ./sources/,								\
							)

#///// PROJECT : OBJECTS //////////////////////////////////////////////////////#

ifeq ($(filter bonus,$(MAKECMDGOALS)), bonus)
OBJECTS_ALL				:=	$(SOURCES_MDT:%.c=%.o) $(SOURCES_BNS:%.c=%.o)
COMPILE_BNS				:=	1
else
OBJECTS_ALL				:=	$(SOURCES_MDT:%.c=%.o)
COMPILE_BNS				:=	0
endif

#///// MAKEFILE : COMMANDS ////////////////////////////////////////////////////#

$(NAME)					:	$(OBJECTS_ALL)
							gcc -fPIE -Wall -Wextra -Werror -g -O3 $(OBJECTS_ALL) ../libasm.a -o $(NAME)
							@touch ../$(NAME)

%.o						:	%.c
							gcc -fPIC -O3 -g -Wall -Werror -Wextra -I ../includes -I ./includes -DCOMPILE_BNS=$(COMPILE_BNS) -c $< -o $@

all						:	$(NAME)

bonus					:	$(NAME)

clean					:
							rm -fr $(OBJECTS_ALL)

fclean					: 	clean
							rm -fr $(NAME)

re						:	fclean all
