# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongclee <dongclee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 15:48:04 by dongclee          #+#    #+#              #
#    Updated: 2024/05/19 13:09:21 by dongclee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_isprint.c ft_strdup.c ft_tolower.c ft_bzero.c ft_memchr.c \
	ft_strlcat.c ft_toupper.c ft_calloc.c ft_memcmp.c ft_strlcpy.c \
	ft_isalnum.c ft_memcpy.c ft_strlen.c ft_isalpha.c ft_memmove.c \
	ft_strncmp.c ft_isascii.c ft_memset.c ft_strnstr.c ft_isdigit.c \
	ft_strchr.c ft_strrchr.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}
INCLUDES = libft.h
CFLAGS = -Wall -Werror -Wextra
CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
