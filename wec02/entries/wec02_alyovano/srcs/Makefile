# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyovano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 12:22:19 by alyovano          #+#    #+#              #
#    Updated: 2020/02/18 12:22:22 by alyovano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_ROOT = ./srcs/libft

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I$(LIBFT_ROOT)

RM = /bin/rm -f
LIB = ar rcs
MAKE = make

NAME = libftprintfgnl.a

SRC = ./srcs/ft_printf/ft_print_c.c ./srcs/ft_printf/ft_print_s.c \
./srcs/ft_printf/ft_print_di.c ./srcs/ft_printf/ft_print_p.c \
./srcs/ft_printf/ft_print_x.c ./srcs/ft_printf/ft_print_u.c \
./srcs/ft_printf/ft_check.c ./srcs/ft_printf/ft_print_special_case.c \
./srcs/ft_printf/ft_printf.c ./srcs/ft_printf/ft_special_case_int.c \
./srcs/ft_printf/ft_print_p_two.c ./srcs/get_next_line.c \


OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h


all: libft_all $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_ROOT)/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

clean: libft_clean
	$(RM) $(OBJ)

fclean: libft_fclean clean
	$(RM) $(NAME)

re: fclean all

libft_all:
	$(MAKE) -C $(LIBFT_ROOT)

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(RM) a.out
	$(MAKE) -C $(LIBFT_ROOT) fclean

.PHONY: all clean fclean re
