/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:05:05 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/11 17:53:24 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Counts the number of nodes in a list.
int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
/*
int main() 
{
    // Create some nodes for testing
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));

    // Initialize data and next pointers
    node1->content = "Node 1";
    node2->content = "Node 2";
    node3->content = "Node 3";
    node3->content = "Node 4";
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    // Test the ft_lstsize function
    int size = ft_lstsize(node1);

    // Print the result
    printf("The size of the list is: %d\n", size);

    // Don't forget to free the memory allocated for the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
