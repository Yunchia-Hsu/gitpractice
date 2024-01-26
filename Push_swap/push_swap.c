/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:06:15 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 15:48:23 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// int    dc_asorted(t_stack_node **lst)
// {
//     t_stack_node    *temp;

//     temp = NULL;
//     if (lst && *lst)
//     {
//         temp = *lst;
//         while (temp)
//         {
//             if (temp->next != NULL && temp->value > temp->next->value)
//             {
//                 printf("temp->index: %d,temp->next->index: %d\n",temp->index, temp->next->index);
//                 printf("temp->value: %d,temp->next->value: %d\n",temp->value, temp->next->value);
//                 return (0);
//             }
//             temp = temp->next;
//         }
//     }
//     return (1);
// }

// static void    print_stack(t_stack_node *stack)//for test
// {
//     t_stack_node *current = stack;

//     while (current != NULL)
//     {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split (argv[1], ' ');
	init_stack_a(&a, argv + 1);//add nodes to stack `a`, which also handles errors;????
	len = stack_len(a);
	if (!stack_sort(a))
	{
		if (len == 2)
			sa(&a, false);
		else if (len == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
    //  printf("before end\n");//test
    //  print_stack(a);//test
	free_stack(&a);
	return (0);
}

