/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:06:41 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/15 19:47:10 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

int	rest_char(t_list **list)
{
	int		i;
	int		k;
	t_list	*last_node;
	t_list	*new_node;
	char	*buffer;

	i = 0;
	k = 0;
	buffer = malloc (BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (-1);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (free(buffer), -1);
	last_node = find_last_node(*list);
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buffer[k++] = last_node->str_buf[i];
	buffer[k] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;
	dealloc(list, new_node, buffer);
	return (0);
}

char	*get_the_line(t_list *list)
{
	int		len_line;
	char	*next_line;

	if (list == NULL)
		return (NULL);
	len_line = count_line(list);
	next_line = malloc(len_line + 1);
	if (next_line == NULL)
		return (NULL);
	copy_str(list, next_line);
	return (next_line);
}

int	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return (-1);
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
	return (0);
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!if_is_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (-1);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			return (free(buf), -1);
		if (char_read == 0)
			return (free(buf), 1);
		buf[char_read] = '\0';
		if (append(list, buf) == -1)
			return (free(buf), -1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = create_list(&list, fd);
	if (!list || status == -1)
		return (dealloc(&list, 0, 0), NULL);
	next_line = get_the_line(list);
	if (next_line == NULL)
		return (dealloc(&list, 0, 0), NULL);
	status = rest_char(&list);
	if (status == -1)
		return (free (next_line), dealloc(&list, 0, 0), NULL);
	return (next_line);
}

// int main()
// {
// 	int		fd;
// 	char	*line;
// 	int		lines;

// 	lines = 1;
// 	fd = open("romeo&juliet.txt", O_RDONLY);
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;
// 	printf("%d->%s",lines++, line = get_next_line(fd));
// 	free(line);
// 	line = NULL;

//     close(fd);
//     return(0);
// }
