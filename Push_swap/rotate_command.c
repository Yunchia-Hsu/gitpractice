/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:11:36 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/12 15:39:51 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"
// bool stack_sort(t_stack_node *stack) //need delete
// {
//     if (!stack)
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

// t_stack_node *find_last_node (t_stack_node *head)//need delete
// {

//     if (head == NULL)
//         return (NULL);
//     while (head->next) 
//         head = head->next;   
//     return (head);
// }

static void    rotate(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *second_node;
    int len;  
        
    last = find_last_node (*stack);
    len = stack_len (*stack);
    if (len == 1 || stack == NULL || *stack == NULL)
        return ;
    second_node = (*stack)->next;
    (*stack)->next->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    (*stack)->next = NULL;
    *stack = second_node;
}



void ra(t_stack_node **a, bool checker)
{
    rotate(a);
    
    if (!checker)
        write(1, "ra\n", 3);
}
  
void rb(t_stack_node **b, bool checker)
{
    rotate(b);
    if (!checker)
        write(1, "rb\n", 3);
}

void rr(t_stack_node **a,t_stack_node **b, bool checker)
{
    rotate(a);
    rotate(b);
    if (!checker)
        write(1, "rr\n", 3);
}


// int main()
// {
//     t_stack_node *b  = NULL; 

//     b = malloc(sizeof(t_stack_node));
//     b->next = malloc(sizeof(t_stack_node));
//     b->next->next = malloc(sizeof(t_stack_node));
//     //b->next->next->next = malloc(sizeof(t_stack_node));

 

//     b->value = 21;
//     b->next->value = 2;
//     b->next->next->value = 3;
    
//     b->prev = NULL;
//     b->next->prev = b;
//     b->next->next->prev = b->next;
//     b->next->next->next = NULL;
    
//     printf("b stack: %d, %d, %d\n", b->value, b->next->value, b->next->next->value);
//     rotate(&b);
//     printf("after rotate b stack: %d, %d, %d\n", b->value, b->next->value, b->next->next->value); 

//     ra(&b, false);
//     printf("b stack: %d, %d, %d\n", b->value, b->next->value, b->next->next->value); 
// }