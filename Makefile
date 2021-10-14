# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:22:54 by tblanco           #+#    #+#              #
#    Updated: 2021/10/14 15:49:30 by tblanco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFTDIR	= libft
SRCDIR		= src
INCDIR		= include
OBJDIR		= obj

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INC			= -iquote$(INCDIR) -iquote$(LIBFTDIR)/$(INCDIR)

SRCS    	:= $(shell find $(SRCDIR) -name '*.c')
OBJS		:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))


$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME)	: $(OBJS)
	make o -C $(LIBFTDIR)
	ar rc $(NAME) $(OBJS) $(shell find $(LIBFTDIR) -name '*.o')
	ranlib $(NAME)
	@printf ${GREEN}"[$@] created\n"${RESET}

clean	:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean	: clean 
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] lib removed\n"$(RESET)

re		: fclean all

test	: all
	$(CC) $(CFLAGS) $(INC) main.c -L./ -lftprintf
	./a.out | cat -e
	rm -f a.out

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
