/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:53:39 by yhsu              #+#    #+#             */
/*   Updated: 2023/12/08 13:13:21 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

int		if_is_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	copy_str(t_list *list, char *next_line);
void	dealloc(t_list **list, t_list *new_node, char *buffer);
int		count_line(t_list *list);
int		rest_char(t_list **list);
char	*get_the_line(t_list *list);
int		append(t_list **list, char *buf, int fd);
int		create_list(t_list **list, int fd);
char	*get_next_line(int fd);


#endif