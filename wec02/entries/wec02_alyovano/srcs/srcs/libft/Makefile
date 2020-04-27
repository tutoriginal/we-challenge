# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 15:18:57 by alyovano          #+#    #+#              #
#    Updated: 2020/01/17 11:17:42 by alyovano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TXT			= @echo "\033[0;35m  Compilation en cours\033[0;35m"

CC			= $(TXT) && gcc

SRC			= ft_isdigit.c ft_memset.c ft_strnstr.c ft_atoi.c ft_isprint.c ft_strchr.c\
			  ft_strrchr.c ft_bzero.c ft_memccpy.c ft_strdup.c ft_tolower.c ft_calloc.c\
			  ft_memchr.c ft_strlcat.c ft_toupper.c ft_isalnum.c ft_memcmp.c  ft_strlcpy.c\
			  ft_isalpha.c ft_memcpy.c  ft_strlen.c ft_isascii.c ft_memmove.c ft_strncmp.c\
			  ft_substr.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			  ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c\
			  ft_putnbr_unsigned_fd.c ft_intlen.c ft_isprintf.c ft_itoa_base.c ft_putstr_len.c\
			  ft_while_print.c ft_capital.c ft_itoa_base_two.c ft_unsigned_itoa.c ft_utoa.c utoa_p_zero_printf.c\

SRCBONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
			  ft_lstiter_bonus.c ft_lstmap_bonus.c\

OBJ			= $(SRC:.c=.o)

OBJBONUS	= $(SRCBONUS:.c=.o)

NAME		= libft.a

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Iinclude

%.c: %.o	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[0;32m[=====LIBFT COMPLETE=====]\033[0;32m"

bonus:		$(OBJBONUS)

			@ar rc $(NAME) $(OBJBONUS)
			@ranlib $(NAME)
			@printf "[Libft_Bonus] Complete\n"

all:		$(NAME)

clean:
	@$(RM) $(OBJ) $(OBJBONUS)
	@echo "Clean process"

fclean:		clean
	@${RM} $(NAME)

re:			fclean all
