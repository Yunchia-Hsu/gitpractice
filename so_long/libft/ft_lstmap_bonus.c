/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:33:58 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:04:06 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
