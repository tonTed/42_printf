# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:22:54 by tblanco           #+#    #+#              #
#    Updated: 2021/10/13 19:34:24 by tblanco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFTDIR	= libft
SRCDIR		= src
INCDIR		= include
OBJDIR		= obj

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -iquote$(INCDIR)

FILES		= printf

SRCS		= $(addprefix $(SRCDIR)/ft_, $(addsuffix .c, $(FILES)))
OBJS		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Colors
BLACK	:= "\e[0;30m"
RED		:= "\e[0;31m"
GREEN	:= "\e[0;32m"
YELLOW	:= "\e[0;33m"
BLUE	:= "\e[0;34m"
MAGENTA	:= "\e[0;35m"
CYAN	:= "\e[0;36m"
RESET	:="\e[0m"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME)	: libft $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@printf ${GREEN}[$(NAME)] created\\n${RESET}

clean	:
	rm -f $(OBJS)

fclean	: clean 
	rm -f $(NAME)

re		: fclean all

libft	:
			make -C $(LIBFTDIR)

.PHONY	: clean fclean all re libft $(OBJS_DIR)

# buildrepo:
# 	@$(call make-repo)

# define make-repo
#    for dir in $(SRCS_DIR); \
#    do \
# 	mkdir -p $(OBJS_DIR)/$$dir; \
#    done
# endef



# $@ : cible de la règle
# $< : premier pré-requis
# $? : noms de tous les pré-requis plus récents que la cible
# $^ : noms de tous les pré-requis
# $* : nom du fichier sans suffixe (pour les règles génériques)
