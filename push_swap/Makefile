# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 18:32:09 by yhsu              #+#    #+#              #
#    Updated: 2024/01/29 09:50:20 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SOURCES  = push_command.c\
			reverse_rotate_command.c\
			rotate_command.c\
			swap_command.c\
			error_handle.c\
			init_nodes_a.c\
			init_nodes_b.c\
			init_stack.c\
			push_swap.c\
			sort_stack.c\
			sort_three.c\
			stack_utils.c
			
OBJECTS = ${SOURCES:.c=.o}

FLAGS = -Wall -Wextra -Werror -I./libft

CC = cc	

%.o: %.c
	${CC} -c ${FLAGS} ${INCLUDES} $< -o $@
	
AR = ar rcs

all: ${NAME}

${NAME}: ${OBJECTS} ${LIBFT}
	cc ${CFLAGS} ${OBJECTS} -L$(LIBFT_DIR) -lft -o ${NAME} 

${LIBFT}:
	make -C libft
		
clean:
	rm -f ${OBJECTS} ${LIBFT}
	@make clean -C ./libft

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re
