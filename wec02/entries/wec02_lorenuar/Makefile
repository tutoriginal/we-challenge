# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2020/04/25 17:18:01 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= color

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

SRCDIR	= src/
INCDIR	= include/
OBJDIR	= objs/

CFLAGS	+= -I $(INCDIR)

SRCS	:= $(wildcard $(SRCDIR)*.c) #			Full path
SRC		:= $(notdir $(SRCS)) # 					Files only
OBJ		:= $(SRC:.c=.o)	#						Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

GR	= \033[32;1m #	Green
RE	= \033[31;1m #	Red
YE	= \033[33;1m #	Yellow
CY	= \033[36;1m #	Cyan
RC	= \033[0m #	Reset Colors

BANNERTXT	= "R A I N B O W - R A I N B O W - R A I N B O W - R A I N B O W - R A I N B O W - R A I N B O W - R A I N B O W"
SLEEPTIME	= 0.2

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJ) to $(NAME)$(RC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)\n"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CC) $(CFLAGS) -I ../$(INCDIR) -c $(CSRCS)

#	runnng

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	-./$(NAME)
	python3 banner.py $(BANNERTXT) | ./$(NAME)  0 200 200
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -b 50 50 50
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -b 50 50 50 0 200 200
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -r
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 2.0
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0.5
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0.5 -rphase 45
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0.5 -rphase 180
	@sleep $(SLEEPTIME)
	-python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0e5 -rphase 45
	@sleep $(SLEEPTIME)
	-python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0.5 -rphase 1e
	@sleep $(SLEEPTIME)
	-python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq 0e5
	@sleep $(SLEEPTIME)
	python3 banner.py $(BANNERTXT) | ./$(NAME) -rfreq -0.5
	@sleep $(SLEEPTIME)
	-./$(NAME)  0 20880 200
	@sleep $(SLEEPTIME)
	-./$(NAME) -b 50 50 50 7 4
	@sleep $(SLEEPTIME)
	-./$(NAME) -b 50 50 50 0 200 200 5566 37

#	cleaning
clean :
	@echo "$(RE)--- Removing $(OBJ)$(RC)"
	@rm -rf $(OBJS) $(OBJDIR)

fclean : clean
	@echo "$(RE)--- Removing $(NAME)$(RC)"
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
