/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:02:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 16:26:46 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node *tmp;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next)
	{
		tmp->next = (*stack)->next;
		tmp->next->prev = tmp;
	}
	else
		tmp->next = NULL;
	(*stack)->next = tmp;
	tmp->prev = *stack;
}

void	sa(t_stack_node **a, bool checker)
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
