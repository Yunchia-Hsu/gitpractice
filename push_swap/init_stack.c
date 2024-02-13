/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:27:58 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/01 17:25:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define malloc fake_malloc

void    *fake_malloc(size_t size)
{
    static int i = 0;

    if (!size)
        write(2, "fake_malloc used\n", ft_strlen("fake_malloc used\n"));
    if (i >= 0)
    {
        i--;
        return (malloc(size));
    }
    else
    {
        i++;
        return (NULL);
    }
}

static int	append(t_stack_node **stack, int n)
{
	t_stack_node	*last_node;
	t_stack_node	*new_node;

	if (!stack)
		return (-1);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (-1);
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
	return (0);
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
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
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
????????????
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	if (!argv)
		return (free_errors(a));
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (check_duplicate(*a, (int) n))
			free_errors(a);
		//append(a, (int)n);
		if (append(a, (int)n) == -1)
			free_errors(a);
		i++;
	}
}
????????