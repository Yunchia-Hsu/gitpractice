/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:08:08 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/31 14:45:13 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0; //not necessary it's for memory leak check
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str)
{
	//看第一個是不是符號或是數字
	if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
		return (1);
	//第一個是符號但第二個不是數字
	if ((*str == '-' || *str == '+' ) && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	//符合第一第二 差之後的事不是數字
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if ((stack)->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
