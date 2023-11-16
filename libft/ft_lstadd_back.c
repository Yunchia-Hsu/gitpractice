/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:31 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 09:02:46 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
/*
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

    // Create a new node and initialize its data
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = "edd";
    new_node->next = NULL;
    ft_lstadd_back(&node1,new_node);

    // Print the modified list
    printf("Modified List:\n");
    current = node1;
    while (current) {
        printf("%s -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");

    // Don't forget to free the memory allocated for the nodes
    //free(node1);
    free(node2);
    free(node3);
    free(new_node);

    return 0;
}
*/