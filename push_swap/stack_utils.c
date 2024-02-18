/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:03:34 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/29 11:29:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(const char *s, char c)
{
	int	i;
	int	count_string;

	count_string = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		count_string = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count_string++;
		i++;
	}
	return (count_string);
}

void	min_on_top(t_stack_node **a)  //Define a function that moves the smallest number to the top
{
	if (*a == NULL)
		return ;
	while ((*a)->value != find_min(*a)->value)//As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median)//Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
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
