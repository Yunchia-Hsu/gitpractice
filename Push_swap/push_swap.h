/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:33:19 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/26 16:14:53 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int		value;
	int		index; //current_index
	int		move_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}	t_stack_node;


//push 
void	pa(t_stack_node **a, t_stack_node **b, bool checker);
void	pb(t_stack_node **b, t_stack_node **a, bool checker);

//rotate
void	ra(t_stack_node **a, bool checker);
void	rb(t_stack_node **b, bool checker);
void	rr(t_stack_node **a,t_stack_node **b, bool checker);
void	rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest_n);

//reverse rotate
void	rra(t_stack_node **a, bool checker);
void	rrb(t_stack_node **b, bool checker);
void	rrr(t_stack_node **a, t_stack_node **b, bool checker);
void	rev_rotate_both(t_stack_node **a,
			t_stack_node **b,t_stack_node *cheapest_node);

//swap
void	sa(t_stack_node **a, bool checker);
void	sb(t_stack_node	**b, bool checker);
void	ss(t_stack_node	**b, t_stack_node	**a, bool checker);

//stack_utils
void			min_on_top(t_stack_node **a);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last_node (t_stack_node *head);
int				stack_len(t_stack_node *stack);

//sort three
bool	stack_sort(t_stack_node *stack);
void	sort_three(t_stack_node **stack);

//error handle 
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **stack);
int		error_syntax(char *str);
int		check_duplicate(t_stack_node *stack, int n);

//sort stack
void	prep_for_push(t_stack_node **stack,		
			t_stack_node *top_node, char stack_name);
void	sort_stacks(t_stack_node **a, t_stack_node **b);

//init nodesb
void	set_target_for_b(t_stack_node *a, t_stack_node *b);
void	init_node_b(t_stack_node *a, t_stack_node *b);

//init node a
void	set_cheapest(t_stack_node *stack);
void	current_index(t_stack_node *stack);
void	set_target_for_a(t_stack_node *a, t_stack_node *b);
void	init_node_a(t_stack_node *a, t_stack_node *b);

//init stack
long	ft_atol(const char *str);
void	init_stack_a(t_stack_node **a, char **argv);

//main
int		main(int argc, char *argv[]);

#endif