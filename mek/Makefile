
SOURCES = test.c ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h

CC = cc

CFLAGS = -fsanitize=address -Wall -Wextra -Werror

NAME = test

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(SOURCES) 

run: $(NAME)
	@echo "Running... \n"
	@./test

clean: 
	@echo "Cleaning..."
	@rm -rf test
	

# test: $(SOURCES)
# 	@echo "Compiling..."
# 	@$(CC) $(CFLAGS) -g $(SOURCES)
# 	@echo "Running... \n"
# 	@./a.out