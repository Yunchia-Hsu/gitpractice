/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:33:58 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/16 17:08:47 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
’f’ on the content of each node.  Creates a new
list resulting of the successive applications of
the function ’f’.  The ’del’ function is used to 
delete the content of a node if needed.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*content_check;

	if (!lst || !f || !del)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		content_check = f(lst->content);
		new_node = ft_lstnew (content_check);
		if (!new_node)
		{
			ft_lstclear (&new_lst, del);
			if (content_check != lst->content)
				free (content_check);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	new_node->next = NULL;
	return (new_lst);
}
