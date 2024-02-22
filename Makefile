# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 15:30:09 by yhsu              #+#    #+#              #
#    Updated: 2024/02/22 17:24:32 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc    

FLAGS = -Wall -Wextra -Werror -I./libft -g
MLX_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}

MLX42_DIR = ./MLX42/build
MLX42 = ./MLX42/build/libmlx42.a
LD_FLAGS = -L/Users/${USER}/.brew/opt/glfw/lib/

INCLUDES = -I/opt/X11/include -Imlx

SOURCES  = map_check.c \
           path_check.c \
           so_long.c\
		   init.c\
		   load_sprite.c\

OBJECTS = ${SOURCES:.c=.o}

all: makelibft ${NAME}

%.o: %.c  ##% 符號代表通配符，可以匹配任意長度的字符串
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

makelibft:
	make -C ${LIBFT_DIR}

${NAME}: ${LIBFT} ${MLX42} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT_INCLUDE} $(MLX42) $(MLX_FLAGS) ${LD_FLAGS} -L${LIBFT_DIR} ${INCLUDES} -lft -o ${NAME} 

${LIBFT}:
	make -C ./libft

${MLX42}:
	make -C ./MLX42

clean:
	rm -f ${OBJECTS}
	@make clean -C ${LIBFT_DIR}   

fclean: clean
	rm -f ${NAME}
	@make clean -C ${LIBFT_DIR} 

re: fclean all

.PHONY: all clean fclean re
