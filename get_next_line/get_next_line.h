/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:11:04 by yhsu              #+#    #+#             */
/*   Updated: 2023/12/01 11:18:38 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
    char    *str_buf;
    struct s_list   *next;
}               t_list;

char    *get_next_line(int fd);
int if_is_newline(t_list *list);
void dealloc(t_list **list, t_list *new_node, char *buffer);
t_list	*find_last_node(t_list *list);
void rest_char(t_list **list);
void copy_str(t_list *list, char *next_line);
int count_line(t_list *list);
char	*get_line(t_list *list);
void create_list(t_list **list, int fd);

#endif