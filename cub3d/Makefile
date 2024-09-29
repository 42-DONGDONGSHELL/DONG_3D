NAME = cub3D

CC = cc
RM = rm -rf
LIBFT = libft.a
MLX = libmlx.a
LIBFT_DIR = libft
MLX_DIR = minilibx
HEADER_DIR = includes
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iminilibx -Iincludes -Ilibft
IFLAGS2 = -Iminilibx -Ilibft libft/libft.a -Lminilibx -lmlx
FFLAGS = -framework OpenGL -framework AppKit


GNL = ./srcs/get_next_line/get_next_line.c \
	./srcs/get_next_line/get_next_line_utils.c \

VALIDATION = ./srcs/validation/simp_validation.c \
	./srcs/validation/file_validation.c \
	./srcs/validation/map_validation.c \

READ_FILE = ./srcs/read_file/parse.c \
	./srcs/read_file/read_file_util.c \
	./srcs/read_file/read_file.c \

RENDER = ./srcs/render/render.c \

SRCS = ./srcs/main.c \
	./srcs/simp_util.c \
	./srcs/trim_util.c \
	$(GNL) \
	$(VALIDATION) \
	$(READ_FILE) \
	$(RENDER) \

all: ${NAME}

OBJS = ${SRCS:.c=.o}

$(NAME) : $(OBJS)
		make -C $(LIBFT_DIR)
		make -C $(MLX_DIR)
		cp $(LIBFT_DIR)/$(LIBFT) .
		cp $(MLX_DIR)/$(MLX) .
		$(CC) $(CFLAGS) -I$(HEADER_DIR) $(OBJS) $(LIBFT) $(IFLAGS2) $(FFLAGS) -o $(NAME)

clean :
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)
		${RM} ${OBJS}

fclean : clean
		make fclean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)
		${RM} $(NAME)
		${RM} $(LIBFT)
		${RM} $(MLX)

re : fclean all

.PHONY:		all bonus clean fclean re
