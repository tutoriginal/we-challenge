CC = gcc

CCFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

EXEC_MORSE = morsec

MAKE = make

SRC = ./srcs/morse_interpreter.c \
	  ./srcs/morse_utils.c \
	  ./srcs/reverse_morse.c \

INCLUDE = morse.h

all:
	$(CC) -o $(EXEC_MORSE) $(SRC)

clean:
	$(RM) $(EXEC_MORSE)
