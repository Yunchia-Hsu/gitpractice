# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:23:12 by yhsu              #+#    #+#              #
#    Updated: 2023/11/22 15:31:04 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_putchar.c\
			ft_putstr.c\
			ft_putdigit.c\
			ft_putdigit_up.c\
			ft_putp.c\
			ft_printf.c\

OBJECTS = ${SOURCES:.c=.o}

all: ${NAME}

${NAME}: ${OBJECTS}
	    ar rc ${NAME} ${OBJECTS}

${OBJECTS}:	${SOURCES}
	    cc ${FLAGS} -c ${SOURCES} -I ft_printf.h

clean:
		rm -f ${OBJECTS}

fclean: clean
		rm -f libftprintf.a

re: fclean all

.PHONY:	all, clean, fclean, re