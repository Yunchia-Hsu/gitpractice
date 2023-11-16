/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:04 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 10:30:33 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Takes as a parameter a node and frees the memory of the node’s content 
//using the function ’del’ given
//as a parameter and free the node.  The memory of ’next’ must not be freed.
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
	return ;
}
/*
void delete_content(void *content) {
    free(content);
}
int main() {
    // Create a node for testing
    t_list *node = malloc(sizeof(t_list));

    //Initialize data and next pointers
    node->content = strdup("Test Content"); 
    // you create a copy of the string, 
    //which gives you control over the memory and 
    allows you to safely free it later. 
    //When you assign a string literal directly, 
    you are working with read-only memory, 
    node->next = NULL;

    // Print the content before deletion
    printf("Content before deletion: %s\n", 
    (char *)node->content);

    // Delete the node using ft_lstdelone
    ft_lstdelone(node, delete_content);

    // Try to print the content after deletion (expect a segmentation fault)
    printf("Content after deletion: %s\n", (char *)node->content);

    return 0;
}
*/