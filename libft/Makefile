# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:30:37 by yhsu              #+#    #+#              #
#    Updated: 2023/11/13 11:50:53 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c\
            ft_bzero.c\
            ft_calloc.c\
            ft_isalnum.c\
            ft_isalpha.c\
            ft_isascii.c\
            ft_isdigit.c\
            ft_isprint.c\
            ft_itoa.c\
            ft_memchr.c\
            ft_memcmp.c\
            ft_memcpy.c\
            ft_memmove.c\
            ft_memset.c\
            ft_putchar_fd.c\
            ft_putendl_fd.c\
            ft_putnbr_fd.c\
            ft_putstr_fd.c\
            ft_split.c\
            ft_strchr.c\
            ft_strdup.c\
            ft_striteri.c\
            ft_strjoin.c\
            ft_strlcat.c\
            ft_strlcpy.c\
            ft_strlen.c\
            ft_strmapi.c\
            ft_strncmp.c\
            ft_strnstr.c\
            ft_strrchr.c\
            ft_strtrim.c\
            ft_substr.c\
            ft_tolower.c\
            ft_toupper.c\
			          
BONUS_SOURCES = ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\

OBJECTS = ${SOURCES:.c=.o}
BONUS_OBJECTS = ${BONUS_SOURCES:.c=.o}
		
all: ${NAME}

${NAME}: ${OBJECTS}
	    ar rc ${NAME} ${OBJECTS}

${OBJECTS}:	${SOURCES}
	    cc ${FLAGS} -c ${SOURCES} -I libft.h

BONUS = .bonus

bonus: ${BONUS}

${BONUS}: ${BONUS_OBJECTS}
	    ar rc ${NAME} ${BONUS_OBJECTS}
		touch ${BONUS}

${BONUS_OBJECTS}:	${BONUS_SOURCES}
				cc	${FLAGS} -c ${BONUS_SOURCES} -I libft.h

clean:
	    rm -f ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	    rm -f libft.a

re: fclean all

.PHONY:	all, clean, fclean, re, bonus