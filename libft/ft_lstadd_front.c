/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:16:12 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 15:05:06 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
	*lst = new;
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
    // Create a new node and initialize its data
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = "start";
    new_node->next = node1;

    // Print the original list
    printf("Original List:\n");
    t_list *current = node1;
    while (current) {
        printf("%s -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");
    // Add the new node to the front of the list
    ft_lstadd_front(&node1, new_node);
    // Print the modified list
    printf("Modified List:\n");
    current = node1;
    while (current) {
        printf("%s -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");
    printf("new_node,%p\nnode1,%p\nnode2,%p\nnode3,%p\n",
       new_node,node1,node2,node3);
    printf("The address of &node1 is: %p\n", &node1);
    printf("The address of &node1 is: %p\n", &new_node);

    // Don't forget to free the memory allocated for the nodes
    //free(node1);
    free(node2);
    free(node3);
    free(new_node);
    return 0;
}
*/