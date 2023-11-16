/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:07:08 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 18:35:45 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.//*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (lst)
	{
		while (*lst)
		{
			next_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_node;
		}
	}
	*lst = NULL;
}

/*
void delete_content(void *content) {
    free(content);
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst)
    {
        del(lst->content);
        free(lst);
    }
    return;
}
int main() 
{
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));

    // Initialize data and next pointers
    node1->content = "hello";
    node2->content = "world";
    node3->content = "haha";
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Print the original list
    printf("Original List:\n");
    t_list *current = node1;
    while (current) {
        printf("%s -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");

    ft_lstclear(&node1, delete_content);
	if(node1 == NULL)
		printf("string is NULL\n");

    // Don't forget to free the memory allocated for the nodes
    //free(node1);
    free(node2);
    free(node3);
    free(node1);

    return 0;
}
*/