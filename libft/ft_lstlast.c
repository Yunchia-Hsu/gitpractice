/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:05:23 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 09:20:20 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Returns the last node of the list.
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
int main() {
    // Create some nodes for testing
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    // Initialize data and next pointers
    node1->content = "Node 1";
    node2->content = "Node 2";
    node3->content = "Node 3";
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Test the ft_lstlast function
    t_list *lastNode = ft_lstlast(node1);

    // Print the content of the last node
    printf("The content of the last node is: %s\n", (char *)lastNode->content);
    printf("The address of lastNode is: %p\n", lastNode);
    printf("The address of &note3 node is: %p\n", node3);
    printf("The address of node2->next is: %p\n", node2->next);
    printf("The address of &node2 is: %p\n", &node3);
    

    // Don't forget to free the memory allocated for the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}*/
