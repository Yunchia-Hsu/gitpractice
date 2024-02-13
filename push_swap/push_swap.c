/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:06:15 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/01 17:02:37 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_n_swap(t_stack_node *a, t_stack_node *b)
{
	if (stack_len(a) == 2)
		sa(&a, false);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				numbers;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	numbers = count_numbers(argv[1], ' ');
	if (argc == 2 && numbers > 1)
		argv = ft_split (argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (argc == 2 && numbers > 1)
		ft_free_split(argv);
	if (!stack_sort(a))
		push_n_swap(a, b); 
	else
		free_stack(&a);
	return (0);
}
