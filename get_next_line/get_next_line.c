/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:06:41 by yhsu              #+#    #+#             */
/*   Updated: 2023/12/01 16:19:02 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int if_is_newline(t_list *list)
{
	int	i;

	if (list == '\0')
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return(0);
}

void dealloc(t_list **list, t_list *new_node, char *buffer)
{
	t_list *tmp;

	if (*list == NULL)
		return;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);//這行程式碼釋放指標 *list 指向的記憶體
		*list = tmp;
	}
	*list = NULL; //這行程式碼將指標 *list 設為 NULL，表示它不再指向任何有效的記憶體位置。
	if (new_node->str_buf != '\0')// 如果非空，將該節點設為新的連結串列開頭
	{
		*list = new_node;
	}
	else
	{
		free(buffer);// 釋放傳入的字串緩衝區
		free(new_node);// 釋放要保留的節點
	}
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	if (list->next)
		list = list->next;
	return (list);
}

void rest_char(t_list **list)//polish list
{
	t_list *last_node; //clean node
	t_list *new_node;//create new node and link the last to the new node
	char *buffer;//put chars after '\n'
	int i;
	int k;

	buffer = malloc (BUFFER_SIZE + 1);
		// malloc new node
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL || last_node == NULL)
		return ;
	// copy chars after'\n' 
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\n' || last_node->str_buf[i] == '\0')
		i++;
	while(last_node->str_buf[i] != '\0' && last_node->str_buf[++i])
		buffer[k++] = last_node->str_buf[i];
	//free all nodes and make list to new node
	buffer[k] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;//why?
	dealloc(list, new_node, buffer);
}

void copy_str(t_list *list, char *next_line)
{
	int i;
	int k;

	k = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				next_line[k++] = '\n';
				next_line[k] = '\0';
				return ;
			}
			next_line[k++] = list->str_buf[i++]; //dont forget to  add char from list to net_line
		}
		list = list->next;
	}
	next_line[k] = '\0';
}

int count_line(t_list *list)//len_to_newline
{
	int	i;
	int	len;

	len = 0;
	if (list == NULL)
		return (0);

	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
		++i;
		++len;
		}
		list = list->next;
	}
	return (len);
}

char	*get_line(t_list *list)
{
	int len_line;
	char *next_line;

	if (list == NULL)
		return (NULL);
	//count how many char till '\n'
	len_line = count_line(list);
	//malloc
	next_line = malloc(len_line + 1);
	if (next_line == NULL)
		return (NULL);
	//copy str to the new_line
	copy_str(list, next_line);
	return (next_line);
}
//append one node to the end of list 
void append (t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)// 如果最後一個節點為空，表示連結串列是空的，將新節點設為連結串列的第一個節點
		*list = new_node;
	else
		last_node->next = new_node;// 否則，將新節點連結到最後一個節點的後面
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!if_is_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
			if (!buf)
				return;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == 0)//read nothing means txt ends
		{
			free(buf);
			return;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;//present line
	char			*next_line;

	list = NULL;
//check read's return, fd, buffer
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0) //read is to check if i can open the file
		return (NULL);
    //create list  
	create_list(&list, fd);//use **list , so we can change the value of the pointer
	if (!list)
		return (NULL);
	
    //fetch the line from list
	next_line = get_line(list);
//add the char after '\n' to next next line
	rest_char(&list);
	return (next_line);
}

int main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("romeo&juliet.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
}
