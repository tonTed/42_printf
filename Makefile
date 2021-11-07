# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:22:54 by tblanco           #+#    #+#              #
#    Updated: 2021/11/07 08:56:53 by tblanco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCDIR		= src
INCDIR		= include
OBJDIR		= obj

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS    	:=	printf \
				libft_utils
					
OBJS		:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, \
				$(addprefix src/ft_, $(addsuffix .c, $(SRCS))))

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

all: $(NAME)

$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@printf ${GREEN}"[$@] created\n"${RESET}

clean	:
	rm -f $(OBJS)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean	: clean 
	rm -f $(NAME)
	@printf $(YELLOW)"[$(NAME)] lib removed\n"$(RESET)

re		: fclean all

test	: all
	$(CC) $(CFLAGS) $(INC) test/main.c -L./ -lftprintf
	@./a.out
	@rm -f a.out

.PHONY	: clean fclean all re libft $(OBJDIR)

# Colors
BLACK	:= "\e[0;30m"
RED		:= "\e[0;31m"
GREEN	:= "\e[0;32m"
YELLOW	:= "\e[0;33m"
BLUE	:= "\e[0;34m"
MAGENTA	:= "\e[0;35m"
CYAN	:= "\e[0;36m"
RESET	:="\e[0m"

# $@ : cible de la règle
# $< : premier pré-requis
# $? : noms de tous les pré-requis plus récents que la cible
# $^ : noms de tous les pré-requis
# $* : nom du fichier sans suffixe (pour les règles génériques)
