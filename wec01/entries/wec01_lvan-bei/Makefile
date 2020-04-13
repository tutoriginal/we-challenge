NAME= morsec

CC= gcc
CFLAGS= -Wall -Wextra -Werror
FILES= src/utils.c src/main.c
FILES_O= utils.o main.o


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -c
	$(CC) $(CFLAGS) $(FILES_O) -o $(NAME)
	mv $(FILES_O) obj/
clean:
	/bin/rm -rf obj/utils.o obj/main.o
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all