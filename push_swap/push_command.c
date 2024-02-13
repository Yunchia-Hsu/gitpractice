/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:50 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 17:41:03 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_p;

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

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write (1, "pb\n", 3);
}
