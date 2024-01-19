/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:33:19 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/19 13:18:35 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int value;
	int index; //current_index
	int move_cost;
	bool above_median;
	bool cheapest;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	struct s_stack_node *target;
}	t_stack_node;


//push 
static void push(t_stack_node **dest, t_stack_node **src);
void pa(t_stack_node **a, t_stack_node **b, bool checker);
void pb(t_stack_node **b, t_stack_node **a, bool checker);

//rotate
static void    rotate(t_stack_node **stack);
void ra(t_stack_node **a, bool checker);
void rb(t_stack_node **b, bool checker);
void rr(t_stack_node **a,t_stack_node **b, bool checker);

//reverse rotate
static void    reverse_rotate(t_stack_node **stack);
void rra(t_stack_node **a, bool checker);
void rrb(t_stack_node **b, bool checker);
void rrr(t_stack_node **a,t_stack_node **b, bool checker);

//swap
static void swap(t_stack_node **stack);
void sa(t_stack_node **a, bool checker);
void	sb(t_stack_node	**b, bool checker);
void	ss(t_stack_node	**b, t_stack_node	**a, bool checker);

//stack_utils
t_stack_node   *find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);
t_stack_node *find_last_node (t_stack_node *head);
int stack_len(t_stack_node *stack);

//split
static int	count_string(const char *s, char c);
static char	*write_word(char *result, const char *s, char c);
static int	ft_free(char **result, int k);
static char	**write_result(char **result, char const *s, char c);
char	**ft_split(char const *s, char c);

//sort three
bool stack_sort(t_stack_node *stack);
void sort_three(t_stack_node **stack);

//main
void	sort_stacks (t_stack_node **a, t_stack_node **b);
static void move_b_to_a(t_stack_node **a, t_stack_node **b);
void	init_node_b(t_stack_node *a, t_stack_node *b);
void	set_target_for_b(t_stack_node *a, t_stack_node *b);
void	init_node_a(t_stack_node *a, t_stack_node *b);
static void move_a_to_b(t_stack_node **a, t_stack_node **b);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void set_cheapest(t_stack_node *stack);
void	move_cost_for_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
void	set_target_for_a(t_stack_node *a, t_stack_node *b);
void init_stack_a(t_stack_node **a, char **argv);
long ft_atol(const char *str);
int check_duplicate(t_stack_node *stack, int n);
int	error_syntax(char *str);
void free_errors(t_stack_node ** stack);
void	free_stack(t_stack_node **stack);
static void append(t_stack_node **stack, int n);
static void min_on_top(t_stack_node **stack);

#endif