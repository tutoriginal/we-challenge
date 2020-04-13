# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2020/04/12 19:29:51 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VOPTS	= --xtree-memory=full --xtree-leak=yes \
# --track-origins=yes --leak-check=full --show-leak-kinds=all -v
# ================================ VARIABLES ================================= #

NAME	= morsec
OPT		= -r "morsec"
OPT1	= "-- --- .-. ... . -.-."

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= src/
INCDIR	= include/
OBJDIR	= objs/

CFLAGS	+= -I $(INCDIR)

SRCS	:= $(wildcard $(SRCDIR)*.c)#			Full path
SRC		:= $(notdir $(SRCS))# 					Files only
OBJ		:= $(SRC:.c=.o)#						Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))#		Full path
CSRCS	:= $(addprefix ../, $(SRCS))#			Compiler

GR		= \033[32;1m#	Green
RE		= \033[31;1m#	Red
WI		= \033[33;1m#	White
CY		= \033[36;1m#	Cyan
RC		= \033[0m#		Reset Colors

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(WI)&&& Linking $(OBJ) to $(NAME)$(RC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)\n"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CC) $(CFLAGS) -I ../$(INCDIR) -c $(CSRCS)

#	runnng

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME) $(OPT)
	./$(NAME) $(OPT1)

# valgrind : re
# 	@printf "$(CY)<> VALGRIND $(RC)\n"
# 	-sudo valgrind $(VOPTS) ./$(NAME) $(OPT)
# 	make fclean
# 	make vclean
#
# vclean :
# 	rm -f *.kcg.*

#	cleaning
clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	@rm -f $(OBJS)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

re : fclean all

debug :
	@echo "SRCS $(SRCS)"
	@echo "SRC $(SRC)"
	@echo "OBJS $(OBJS)"
	@echo "OBJ $(OBJ)"
	@echo "CSRCS $(CSRCS)"
	@echo "CFLAGS $(CFLAGS)"

.PHONY	= all run clean fclean re debug
