NAME = color

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_FILES = color.h

SRC_FILES = main.c reader.c init.c term_util.c print.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(RED)$(NAME) compiled$(NC)"

clean:
	@rm -f $(OBJ_FILES)
	@echo "$(GREEN)$(NAME) cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) fcleaned$(NC)"

debug: $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $@ $^ -fsanitize=address
	@echo "$(RED)debug compiled$(NC)"

re: fclean all