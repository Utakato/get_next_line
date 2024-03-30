
SOURCES = get_next_line.c get_next_line_utils.c get_next_line.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) 