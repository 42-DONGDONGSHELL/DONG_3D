NAME = cub3D

SRC_DIR = srcs
OBJ_FILES	= ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iminilibx -Iincludes -Ilibft
IFLAGS2 = -Iminilibx -Ilibft libft/libft.a -Lminilibx -lmlx
FFLAGS = -framework OpenGL -framework AppKit

SRCS = ./srcs/main.c \

all: ${NAME}

${NAME}: ${OBJ_FILES} libft libmlx
	$(CC) $(CFLAGS) $(OBJ_FILES) $(IFLAGS2) $(FFLAGS) -o ${NAME}

${SRC_DIR}/%.o: ${SRC_DIR}/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft:
	make -C libft
libmlx:
	make -C minilibx
clean:
	rm -f $(OBJ_FILES)
	make -C libft clean
	make -C minilibx clean
fclean: clean
	rm -f $(NAME) ./libft/libft.a
re: fclean all
.PHONY: all libft clean fclean re
