/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:03:17 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/13 09:18:50 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
/*
void print_content(void *content) {
    printf("%s\n", (char *)content);
}

int main() {
    // Create a linked list
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    // Initialize data and next pointers
    node1->content = "First Node";
    node1->next = node2;

    node2->content = "Second Node";
    node2->next = node3;

    node3->content = "Third Node";
    node3->next = NULL;

    // Apply ft_lstiter to print the content of each node
    ft_lstiter(node1, print_content);

    // Don't forget to free the memory allocated for the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/