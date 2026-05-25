NAME = code

C = gcc
CFLAGS = -Wall -Wextra -I$(INC_DIR)
DFLAGS = -g -O0 -DDEBUG
RFLAGS = -O2 -DRELEASE

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

SRC =	main.c figure2_1.c 2_1_7.c
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

debug: CFLAGS += $(DFLAGS)
debug: re

release: CFLAGS += $(RFLAGS)
release: re

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(C) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re debug release
