NAME		:= prediction_program

CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -Isrc/include

SRC := \
	src/main.c

OBJ := $(SRC:src/%.c=objects/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

objects/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re