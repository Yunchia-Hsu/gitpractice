/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:02:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/12 14:50:13 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

// bool stack_sort(t_stack_node *stack)//need delete
// {
//     if (stack == NULL)
//         return (1);
//     if (stack->next)
//     {
//         if (stack->value > stack->next->value)
//             return (false);
//         stack = stack->next;
//     }
//     return (true);
// } 

// int stack_len(t_stack_node *stack) //need delete
// {
//     int count;

//     count = 0;
//     if (stack == NULL)
//         return (0);
//     while (stack)
//     {
//         count++;
//         stack = stack->next;
//     }
//     return (count);
// }

static void swap(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;
    t_stack_node *tmp3;
    int len;

    len = stack_len(*stack);
    if (len == 1 || stack == NULL || *stack == NULL)
        return ;
    tmp = *stack;
    tmp2 = (*stack)->next;
    tmp3 = (*stack)->next->next;
    (*stack)->next->next->prev = tmp;
    tmp->next = tmp3;
    tmp2->next = tmp;
    tmp2->prev = NULL;
    *stack = tmp2;
}

void sa(t_stack_node **a, bool checker)
{
    swap(a);
    if (!checker)
        write(1, "sa\n",3);
}

void	sb(t_stack_node	**b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node	**b, t_stack_node	**a, bool checker)
{
	swap(b);
    swap(a);
	if (!checker)
		write(1, "ss\n", 3);
}

// int main()
// {
//     t_stack_node *a;
//     t_stack_node *b = NULL; 
//     a = malloc(sizeof(t_stack_node));
//     a->next = malloc(sizeof(t_stack_node));
//     a->next->next = malloc(sizeof(t_stack_node));
//     a->next->next->next = malloc(sizeof(t_stack_node));
//     b = malloc(sizeof(t_stack_node));
//     b->next = malloc(sizeof(t_stack_node));
//     b->next->next = malloc(sizeof(t_stack_node));
//     b->next->next->next = malloc(sizeof(t_stack_node));

//     a->value = -26;
//     a->next->value = 0;
//     a->next->next->value = 50;
//     a->next->next->next->value = 52;
//     a->prev = NULL;
//     a->next->prev = a;
//     a->next->next->prev = a->next;
//     a->next->next->next->prev = a->next->next;

//     b->value = 1;
//     b->next->value = 2;
//     b->next->next->value = 3;
//     b->next->next->next->value = 4;
//     b->prev = NULL;
//     b->next->prev = b;
//     b->next->next->prev = b->next;
//     b->next->next->next->prev = b->next->next;


    
//     printf("a stack: %d, %d, %d,%d\n", a->value, a->next->value, 
//     a->next->next->value, a->next->next->next->value);
//     printf("b stack: %d, %d, %d,%d\n", b->value, b->next->value, 
//     b->next->next->value, b->next->next->next->value);
//     swap(&a);
//     sb(&b, true);
//     printf("swap a: %d, %d, %d,%d\n", a->value, a->next->value, 
//     a->next->next->value, a->next->next->next->value);
// }