NAME		:= training_program

CC		:= g++
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -Isrc/include

SRC := \
	src/main.cpp

OBJ := $(SRC:src/%.cpp=objects/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

objects/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re