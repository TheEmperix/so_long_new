NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
FLAGS_M = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

HEADER = ./src/so_long.h ./gnl/get_next_line.h

HEAD_BONUS = ./src_bonus/so_long_bonus.h ./gnl/get_next_line.h

SRC = ./src/so_long.c ./src/check.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./src/draw.c ./src/move.c \
			./src/search.c ./src/utils.c ./src/ft_itoa.c

SRC_BONUS = ./src_bonus/so_long.c ./src_bonus/check.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c\
			./src_bonus/draw.c ./src_bonus/move.c ./src_bonus/search.c ./src_bonus/utils.c ./src_bonus/ft_itoa.c\
			./src_bonus/animation.c

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))

all:	$(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(FLAGS) $(FLAGS_M) $(OBJ) -o $(NAME)

bonus:		$(OBJ_BONUS)
			$(CC) $(FLAGS) $(FLAGS_M) $(OBJ_BONUS) -o $(NAME)

%.o:	%.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) ${OBJ}
		$(RM) ${OBJ_BONUS}

fclean:	clean
		$(RM) so_long

re:	fclean all

.PHONY: all clean fclean re

