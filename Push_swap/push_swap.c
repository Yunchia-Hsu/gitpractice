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

char    **split(char *s, char c)

free_error()

error_syntax(argv[i])

check_duplicate(argv[i])

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
		if  (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (check_duplicate(*a, n))//if (error_duplicate(*a, (int)n))
			free_error(a);
		
		append_node(a, n);

		i++; 
	}
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
    if (argc == 1 || (argc ==2 && !argv[1][0]))
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