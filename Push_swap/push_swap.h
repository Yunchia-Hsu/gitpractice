/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:33:19 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/12 17:01:30 by yhsu             ###   ########.fr       */
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
	int current_position;
	int push_cost;
	bool aboce_median;
	bool cheapest;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	struct s_stack_node *target;
}	t_stack_node;

t_stack_node    *find_max(t_stack_node *stack);


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

#endif