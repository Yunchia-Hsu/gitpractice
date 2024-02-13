/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:07:13 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/19 13:00:26 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_long(long number, int digit)
{
	long long	llong_max;

	llong_max = 9223372036854775807;
	if (number > llong_max / 10)
		return (1);
	else if (number * 10 > llong_max - digit)
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (((str[i] == '+') || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign = 0;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		if (check_long(result, str[i] - '0'))
			return (sign * -1);
		result = result * 10 + (str[i++] - '0');
	}
	if (! sign)
		result = result * -1;
	return (result);
}
