/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:07:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/14 16:07:22 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
/*
int main()
{
	char	str1[] = "+47+5";
	char	str2[] = "+548";
	char	str3[] = "123";
	char	str4[] = "3&4567";
	char	str5[] = "3&4567";
	printf("str 47: %d\nstr 548: %d\nstr2 123: %d\nstr : %d\nstr : %d\n",
		atoi(str1),ft_atoi(str2),ft_atoi(str3),ft_atoi(str4),ft_atoi(str5));
}
*/