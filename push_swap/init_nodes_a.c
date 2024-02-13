/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:26 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/01 11:35:33 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack_node *stack)
{
	int				i;
	long			cost_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	i = 0;
	cost_value = LONG_MAX;
	while (stack)
	{
		if (stack->move_cost < cost_value)
		{
			cost_value = stack->move_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

static void	move_cost_for_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->move_cost = a->index;
		if (!(a->above_median))
			a->move_cost = len_a - (a->index);
		if (a->target->above_median)
			a->move_cost += a->target->index;
		else
			a->move_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	len;
	int	mediam;

	i = 0;
	len = stack_len(stack);
	mediam = len / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= mediam)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_for_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match;

	while (a)
	{
		current_b = b;
		best_match = LONG_MIN;
		while (current_b)
		{
			if (a->value > current_b->value && current_b->value > best_match)
			{
				best_match = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	init_node_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_for_a(a, b);
	move_cost_for_a(a, b);
	set_cheapest(a);
}
