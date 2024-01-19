/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:03:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/19 17:39:53 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

//find smallesr nmb
t_stack_node   *find_min(t_stack_node *stack)
{
    t_stack_node    *min_node;
    long    min;
    
    if (stack == NULL)
        return (NULL);
    min_node = stack;
    while (stack)
    {
        if (stack->value < min_node->value && stack->value < min)
            min_node = stack; 
        stack = stack->next;
    }
    return(min_node);
}

//find biggest nmb
t_stack_node    *find_max(t_stack_node *stack)
{
    t_stack_node    *max_node;
    long            max;
    
    if (stack == NULL)
        return (NULL);
    max_node = stack;
    max = LONG_MIN;
    while (stack)
    {
        if (stack->value > max)
         {
               max_node = stack;
               max = stack->value;
         }  
        stack = stack->next; 
    }
    return (max_node);
}

t_stack_node *find_last_node (t_stack_node *head)
{
    
    if (head == NULL)
        return (NULL);
    while (head->next != NULL) 
        head = head->next;   
    return (head);
}


int stack_len(t_stack_node *stack)
{
    int count;

    count = 0;
    if (stack == NULL)
        return (0);
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}



// int main()
// {
//     t_stack_node *a;
//     t_stack_node *b = NULL; 
//     t_stack_node *c; 
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

//     c = find_max(b);
//     printf("max node: %d\n", c->value);
//     printf("a stack: %d, %d, %d,%d\n", a->value, a->next->value, 
//     a->next->next->value, a->next->next->next->value);
    
    
// }