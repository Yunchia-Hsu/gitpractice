/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:27:58 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 15:25:42 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void append(t_stack_node **stack, int n)
{
	t_stack_node *last_node;
	t_stack_node *new_node;


	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return;//error check not sure whether to free list
	new_node->next = NULL;
	new_node->value = n;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

long	ft_atol(const char *str)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (check_duplicate(*a, (int)n))//if (error_duplicate(*a, (int)n))
			free_errors(a);
		append(a, (int)n);

		i++;
	}
}
