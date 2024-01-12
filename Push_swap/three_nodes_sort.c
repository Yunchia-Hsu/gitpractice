/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nodes_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:13 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/12 15:49:18 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//check if stack is asceding
bool stack_sort(t_stack_node *stack)
{
    if (!stack)
        return (1);
    if (stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
} 

void sort_three(t_stack_node **stack)
{
    t_stack_node    *max_node;
    
    max_node = find_max(*stack);
    if (max_node == *stack)
    {
        ra(stack, false);
        printf("sort3 after ra: %d, %d, %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
    }
    else if (max_node == (*stack)->next)
        rra(stack, false);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack, false); 
}

int main()
{
    t_stack_node *b; 

    b = malloc(sizeof(t_stack_node));
    b->next = malloc(sizeof(t_stack_node));
    b->next->next = malloc(sizeof(t_stack_node));
    //b->next->next->next = malloc(sizeof(t_stack_node));


    b->value = 2;
    b->next->value = 3;
    b->next->next->value = 52;
    b->next->next->next = NULL;
    
    //b->prev = NULL;
    b->next->prev = b;
    b->next->next->prev = b->next;
    
    printf("b stack: %d, %d, %d\n", b->value, b->next->value, b->next->next->value);
    sort_three(&b);
    printf("b stack: %d, %d, %d\n", b->value, b->next->value, b->next->next->value); 
}