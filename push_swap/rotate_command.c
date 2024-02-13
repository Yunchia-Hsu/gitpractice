/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:11:36 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 16:57:06 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_node;
	int				len;

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

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack_node **a,
			t_stack_node **b, t_stack_node *cheapest_n)
{
	while (*a != cheapest_n && *b != cheapest_n->target)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
