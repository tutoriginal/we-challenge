NAME =		morse.a

SRCS =		morse.c utils.c b_tree.c

OBJS =		$(SRCS:.c=.o)

HEADER = 	./

%.o: %.c
		gcc -Wall -Wextra -Werror -c -I$(HEADER) -o $@ $<

all:		$(NAME)

$(NAME): 	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJS) $(OBJB)

fclean:     	clean
		/bin/rm -f $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re bonus
