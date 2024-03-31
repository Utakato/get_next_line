
SOURCES = test.c ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(SOURCES) 

run: $(NAME)
	@echo "Running... \n"
	@./a.out