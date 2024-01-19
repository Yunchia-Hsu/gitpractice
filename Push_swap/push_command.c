/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:50 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/19 17:00:28 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node *node_p;
    
    if (*src == NULL || src == NULL)
        return ;
    node_p = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_p->prev = NULL;
    if (*dest == NULL)
    {
        *dest = node_p;
        node_p->next = NULL;
    }
    else
    {
        node_p->next = *dest;
        (*dest)->prev = node_p;
        *dest = node_p;
    }
}

void pa(t_stack_node **a, t_stack_node **b, bool checker)
{
    push(a, b);
    if (!checker)
        write (1, "pa\n",3);
}

void pb(t_stack_node **b, t_stack_node **a, bool checker)
{
    push(b, a);
    if (!checker)
        write (1, "pb\n",3);
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

//     a->value = -1;
//     a->next->value = 0;
//     a->next->next->value = 1;
//     a->next->next->next->value = 2;
//     a->prev = NULL;
//     a->next->prev = a;
//     a->next->next->prev = a->next;
//     a->next->next->next->prev = a->next->next;

//     b->value = 4;
//     b->next->value = 5;
//     b->next->next->value = 6;
//     b->next->next->next->value = 7;
//     b->prev = NULL;
//     b->next->prev = b;
//     b->next->next->prev = b->next;
//     b->next->next->next->prev = b->next->next;


    
//     printf("a stack: %d, %d, %d,%d\n", a->value, a->next->value, 
//     a->next->next->value, a->next->next->next->value);
//     printf("b stack: %d, %d, %d,%d\n", b->value, b->next->value, 
//     b->next->next->value, b->next->next->next->value);
//     push(&b, &a);
//     printf("push a: %d, %d, %d\n", a->value, a->next->value, 
//     a->next->next->value);
//     printf("push b: %d, %d, %d, %d, %d\n", b->value, b->next->value, 
//     b->next->next->value, b->next->next->next->value,b->next->next->next->next->value);
// }