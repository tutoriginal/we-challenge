# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/12 18:44:33 by agossuin          #+#    #+#              #
#    Updated: 2020/04/12 21:45:29 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC_NAMES	=	morsec.c get_next_line.c chained_lists.c wav.c

SRC			=	$(addprefix srcs/, $(SRC_NAMES))

NAME		=	morsec

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):
			$(CC) $(FLAGS) -o $(NAME) $(SRC)
			make clean

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) morse.wav

re:			fclean all
