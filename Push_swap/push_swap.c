/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:06:15 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/19 18:13:10 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "push_swap.h"

static void    print_stack(t_stack_node *stack)//for test
{
    t_stack_node *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


static void min_on_top(t_stack_node **stack)
{
	while( (*stack)->value != find_min(*stack)->value)
	{
		if ((*stack)->above_median)
			ra(stack, false);
		else 
			rra(stack, false);
		*stack = (*stack)->next;
	}
}

static void append(t_stack_node **stack, int n)
{
	t_stack_node *last_node;
	t_stack_node *new_node;

	
	if(!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;//error check not sure whether to free list
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

void free_errors(t_stack_node **stack)
{
	free_stack(stack);
	write(1, "Error\n",6);
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
	while(*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int check_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while(stack)
	{
		if ((stack)->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long ft_atol(const char *str)
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
			n = n * 10 + (str[i]- 48);
		i++;
	}
	return (n * sign);
}


void init_stack_a(t_stack_node **a, char **argv)
{
    long	n;
    int		i;
	
	i= 0;
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


 
void set_target_for_a(t_stack_node *a, t_stack_node *b)//找出比本身小但是是逼裡面最大的值
{
	//compare current node and next match node 
	//t_stack_node	*current_a;
	t_stack_node	*target_node;
	long 			best_match;
  // example has current_b this node not sure why????
	
	while (a)
	{
		best_match = LONG_MIN;
		while(b)
		{
			
			if (a->value > b->value && b->value > best_match)
			{
				best_match = b->value;
				target_node = b;
			}
			b = b->next;;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;;
	}
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	len;
	int	mediam;
	
	i = 0;
	len = stack_len(stack);
	mediam = len / 2;
	while(stack)
	{
		stack->index = i;
		if(stack->index <= mediam)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	move_cost_for_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	

	len_a = stack_len(a);
	len_b = stack_len(b);
	
	while(a)
	{
		a->move_cost = a->index;
		
		if (!(a->above_median))
			a->move_cost = len_a - (a->index);
		if (a->target->above_median)
			a->move_cost = a->move_cost + len_b;
		else if (!(a->target->above_median))
			a->move_cost = a->move_cost + (len_b - (a->target->index));

		a = a->next;
	}
}

void set_cheapest(t_stack_node *stack)//找push cost 裡面最小的值
{
  int	i;
  long	cost_value;
  t_stack_node *cheapest_node;
  
  if (!stack)
	return;
  i = 0;
  cost_value = LONG_MAX;
  while (stack)
  {
	if (stack->move_cost < cost_value)
	{
		cheapest_node = stack;
		cost_value = stack->move_cost;
	}
	 stack = stack->next;	
  }
  cheapest_node->cheapest = true;
}



void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a' && top_node->above_median)
		{
			printf("test\n");
			printf("%d\n", (*stack)->value);
			ra(stack, false);
		}
		else if (stack_name == 'a' && ! (top_node->above_median))
			rra(stack, false);	
		if (stack_name == 'b' && top_node->above_median)
			rb(stack, false);
		else if (stack_name == 'b' && !(top_node->above_median))
			rrb(stack, false);	
	}
}


static void move_a_to_b(t_stack_node **a, t_stack_node **b)//決定要如何移動node a & target node
{
	t_stack_node *cheapest_n;
	
	t_stack_node *current_a;
	
	current_a = *a;
	while (current_a)//get cheapest
	{
		if (current_a->cheapest == true)
			cheapest_n = current_a;
		current_a = current_a->next;
	} 
	if (cheapest_n->above_median && cheapest_n->target->above_median)//rotate both if seperate the function should add current_index
	{
		if (*a != cheapest_n && *b != cheapest_n->target)
			rr(a, b, false);
	}
	else if (!(cheapest_n->above_median) && !(cheapest_n->target->above_median)) //rever rotate both
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
	prep_for_push(a, cheapest_n, 'a');
	prep_for_push(b, cheapest_n->target, 'b');
	pb(b, a, false);
}


void	init_node_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	printf("test11\n");
	current_index(b);
	set_target_for_a(a, b);
	move_cost_for_a(a, b);
	set_cheapest(a);
	printf("init node a\n");
	print_stack(a);
}

void	set_target_for_b(t_stack_node *a, t_stack_node *b)//找出比本身big但是是逼裡面最small的值
{
	t_stack_node *current_a;
	t_stack_node *target;
	long	best_match;

	while(b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while(current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;	
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_node_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_for_b(a, b);
}


static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target, 'a');//make sure bnode's target is on the top 
	pa(a, b, false);
}



void	sort_stacks (t_stack_node **a, t_stack_node **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a > 3 && !stack_sort(*a))
	{
		pb(b, a, false);
		len_a--;
	}
	if (len_a > 3 && !stack_sort(*a))
	{
		pb(b, a, false);
		len_a--;
	}
	while (len_a > 3 && !stack_sort(*a))
	{
		init_node_a(*a, *b);
		printf("after init node a\n");
		print_stack(*a);
		move_a_to_b(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);//why take pointer
		
		printf("init node b\n");
		printf ("node b value :%d\n", (*b)->value);
		
		move_b_to_a(a, b);//why take double pointer
		*b = (*b)->next;//???
	}
	current_index(*a);
	min_on_top(a);	
}



int	main(int argc, char *argv[])
{
    t_stack_node *a;
    t_stack_node *b;
    long i;
    int len;
    
    a = NULL;
    b = NULL;
	//check input 
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split (argv[1], ' ');
		
    
    init_stack_a(&a, argv + 1);//add nodes to stack `a`, which also handles errors;????
    printf("in main after len\n");
	print_stack(a);
	len = stack_len(a);
	
	printf("len: %d\n", len);
	print_stack(a);
	if (!stack_sort(a))
    {
        if (len == 2)
		{
	        printf("1\n");
			sa(&a, false);
		}
        else if (len == 3)
		{
			printf("in stack sort\n");
		    sort_three(&a);
		}
		else
		{
			// b = (t_stack_node *)malloc(sizeof(t_stack_node));
			// b = new_stack_node();
			// new_stack_node() 
			// {
			// 	t_stack_node *new_node;
			// 	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
			// 	if (new_node != NULL) {
			// 		new_node->next = NULL;
			// 		new_node->prev = NULL;
			// 		new_node->target_node = NULL;
			// 		new_node->above_median = 0;
			// 		new_node->cheapest = 0;
			// 		new_node->index = 0;
			// 		new_node->nbr = 0;						
			// 	}
			// 	return (new_node);
			// }
		    sort_stacks(&a, &b);
			
		}
    }
	printf("before print_stack\n");
	print_stack(a);
    free_stack(&a);
    return (0);
}