/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:14 by yhsu              #+#    #+#             */
/*   Updated: 2023/11/22 19:17:30 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putdigit_p(unsigned long n, unsigned int base)
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

int	ft_putp(unsigned long n)
{
	int	len;

	if (! n)
		return (ft_putstr("0x0"));
	else
		if (write(1, "0x", 2) == -1)
			return (-1);
	len = ft_putdigit_p(n, 16);
	if (len == -1)
		return (-1);
	return (len + 2);
}
