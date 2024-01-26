/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:03:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 16:25:23 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	if (*a == NULL)
		return ;
	while ((*a)->value != find_min(*a)->value) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}

t_stack_node	*find_min(t_stack_node *stack)
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

//find biggest nmb
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

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

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
