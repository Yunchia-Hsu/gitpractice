/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:11:40 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/22 19:16:28 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_putdigit(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_putdigit(n / base, base);
		if (count == -1)
			return (-1);
		return (count + ft_putdigit(n % base, base));
	}
}
