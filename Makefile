# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:22:54 by tblanco           #+#    #+#              #
#    Updated: 2021/10/06 10:55:51 by tblanco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.ad

CFLAGS		= -Wall -Wextra -Werror
CC			= gcc

FILES		= printf

SRCS		= $(addprefix ./ft_, $(addsuffix .c $(FILES)))

OBJS		= $(SRCS:.c=.o)

# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

.c.o	:
			$(CC) $(CFLAGS) -iquote -c $< -o ${<:.c=.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
			@printf ${GREEN}[$(NAME)] created\n${RESET}

clean	:
			rm -f $(OBJS)

fclean	: clean 
			rm -f $(NAME)

re		: fclean all

.PHONY	: clean fclean all re