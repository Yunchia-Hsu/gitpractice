/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:59:51 by yhsu              #+#    #+#             */
/*   Updated: 2023/12/07 17:11:53 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	if_is_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{

	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	copy_str(t_list *list, char *next_line)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
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
			next_line[k++] = list->str_buf[i++];
		}
		list = list->next;
	}
	next_line[k] = '\0';
}

void	dealloc(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL)// 如果链表为空，直接返回，无需进行释放操作
		return ;
	while (*list)// 遍历链表，释放每个节点的内存
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);//這行程式碼釋放指標 *list 指向的記憶體
		*list = tmp;
	}
	//*list = NULL; //這行程式碼將指標 *list 設為 NULL，表示它不再指向任何有效的記憶體位置。
	// if (new_node->str_buf[0])
	// {
	// 	*list = new_node;// 如果新节点的字符串缓冲区非空，将新节点设为链表的头节点
	// // 	//printf("list in dealloc: %s\n", new_node->str_buf);
	// }
	// else
	// {
	// 	free(buffer);// 釋放傳入的字串緩衝區
	// 	free(new_node);// 釋放要保留的節點
	// }
}

int	count_line(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
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
