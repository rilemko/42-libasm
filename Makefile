# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:43:39 by mconreau          #+#    #+#              #
#    Updated: 2025/09/01 22:14:07 by mconreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#///// PROJECT : CONFIGURATION ////////////////////////////////////////////////#

# > GENERAL <<<<<<<<<<<<<<

NAME					:=	libasm.a

#///// PROJECT : SOURCES //////////////////////////////////////////////////////#

SOURCES_MDT				:=	$(addprefix ./sources/,								\
							ft_read.s											\
							ft_strcmp.s											\
							ft_strcpy.s											\
							ft_strdup.s											\
							ft_strlen.s											\
							ft_write.s											\
							)

SOURCES_BNS				:=	$(addprefix ./sources/,								\
							)

#///// PROJECT : OBJECTS //////////////////////////////////////////////////////#

OBJECTS_MDT				:=	$(SOURCES_MDT:%.s=%.o)
OBJECTS_BNS				:=	$(SOURCES_BNS:%.s=%.o)
ifeq ($(filter bonus,$(MAKECMDGOALS)), bonus)
OBJECTS_ALL				:=	$(OBJECTS_MDT) $(OBJECTS_BNS)
COMPILE_BNS				:=	1
else
OBJECTS_ALL				:=	$(OBJECTS_MDT)
COMPILE_BNS				:=	0
endif

#///// MAKEFILE : COMMANDS ////////////////////////////////////////////////////#

$(NAME)					:	$(OBJECTS_ALL)
							ar -rcs $(NAME) $(OBJECTS_ALL)
							@touch $(NAME)

%.o						:	%.s
							nasm -DPIC -f elf64 $< -o $@

all						:	$(NAME)

bonus					:	$(NAME)

clean					:
							rm -fr $(OBJECTS_MDT) $(OBJECTS_BNS)

fclean					: 	clean
							rm -fr ./$(NAME)

re						:	fclean all
