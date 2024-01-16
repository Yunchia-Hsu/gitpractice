/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:06:15 by yhsu              #+#    #+#             */
/*   Updated: 2024/01/12 19:42:31 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "push_swap.h"

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
char    **split(char *s, char c)

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

void free_errors(t_stack_node ** stack)
{
	free_stack(stack);
	write(1, "Error\n",6);
	exist (1);
}

int	error_syntax(char *str)
{
	//看第一個是不是符號或是數字
	if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
		return (1);
	//第一個是符號但第二個不是數字
	if ((str == '-' || str == '+' ) && !(*str[1] >= '0' && *str[1] <= '9'))
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
			free_error(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (check_duplicate(*a, n))//if (error_duplicate(*a, (int)n))
			free_error(a);
		
		append_node(a, n);

		i++; 
	}
}
void set_cheapest(t_stack_node *stack)//找push cost 裡面最小的值
{
 //
}

static void	cost_analysis(t_stack_node *a, t_stack_node *b)
{ // a轉上來的次數 + target 轉上來的次數 
 //先算cost a 設定cost a is index 如果在中上 就正確 如果a位置在中下 cost = len - index a 
//target cost 如果中上 直接相加
//如果中下 cost a + len_b -  a->target-index 
}
 
set_target_a(t_stack_node *a, t_stack_node *b)//找出比本身小但是是逼裡面最大的值
{
	//compar e curent node and nest match node 
}

current_index(t_stack_node *stack_len)
{

}

static move_a_to_b(t_stack_node *a, t_stack_node *b)//決定要如何移動node a & target node
{
	  
}





sort_stack()
{

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
    len = stack_len (argv);
    init_stack_a(&a, argv + 1);//Initiate stack `a`, which also handles errors;????
    if (!stack_sort(a))
    {
        if (len == 2)
            sa(&a, false);
        else if (len == 3)
            sort_three(&a);
        else
        {
            sort_stack(&a, &b);
        }
    }
    free_stack(&a);
    return (0);
}

