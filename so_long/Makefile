# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 15:30:09 by yhsu              #+#    #+#              #
#    Updated: 2024/02/15 16:48:34 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc	
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
MLX42_DIR = ./MLX42
MLX42 = ./MLX42/libmlx42.a

SOURCES  = map_check.c\
				##so_long.c\
			
OBJECTS = ${SOURCES:.c=.o}

FLAGS = -Wall -Wextra -Werror -I./libft
MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit


%.o: %.c
	${CC} -c ${FLAGS} ${INCLUDES} $< -o $@
	

all: ${NAME}

${NAME}: ${OBJECTS} ${LIBFT} ${MLX42}
	cc ${CFLAGS} ${OBJECTS} -L$(LIBFT_DIR) -L${MLX42_DIR} -lft -o ${NAME} 

${LIBFT}:
	make -C ./libft

${MLX42}:
	make -C ./MLX42
		
clean:
	rm -f ${OBJECTS} ${LIBFT} ${MLX42}
	@make clean -C ./libft 
	@make clean -C ./MLX42

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@$(MAKE) fclean -C ./MLX42
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re
