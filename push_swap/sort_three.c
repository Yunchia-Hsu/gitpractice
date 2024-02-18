/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:13 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/29 11:26:49 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_min(t_stack_node *stack) //check if stack is asceding
{
	t_stack_node	*min_node;
	long			min;

	if (stack == NULL)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min_node = stack;
			min = min_node->value;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max;

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

bool	stack_sort(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*max_node;

	if (*stack == NULL)
		return ;
	max_node = find_max(*stack);
	 //printf("in sort three max_node : %d\n", max_node->value);
	if (max_node == *stack)
		ra(stack, false);
	else if (max_node == (*stack)->next)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}
